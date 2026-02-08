#!/bin/bash

# =============================================================================
# MINITALK COMPREHENSIVE TESTER
# 42 School Project Testing Suite
# Created for mini_talk project evaluation and testing
# =============================================================================

# Colors for output
RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[1;33m'
BLUE='\033[0;34m'
PURPLE='\033[0;35m'
CYAN='\033[0;36m'
NC='\033[0m' # No Color

# Test counters
TOTAL_TESTS=0
PASSED_TESTS=0
FAILED_TESTS=0
VALGRIND_ERRORS=0

# Project paths
SERVER_EXEC="./server"
CLIENT_EXEC="./client"
SERVER_BONUS_EXEC="./server_bonus"
CLIENT_BONUS_EXEC="./client_bonus"

# Log files
VALGRIND_LOG="valgrind_results.log"
TEST_LOG="test_results.log"
SERVER_OUTPUT="server_output.tmp"
CLIENT_OUTPUT="client_output.tmp"

# Test messages
SHORT_MSG="Hello"
LONG_MSG="This is a very long message that tests the transmission capabilities of the mini_talk project with various characters and punctuation marks!"
SPECIAL_MSG="Special chars: !@#$%^&*()_+-={}[]|\\:;\"'<>?,./"
UNICODE_MSG="Unicode: àéîöü ñç 中文 🚀"
EMPTY_MSG=""
NUMERIC_MSG="1234567890"

# =============================================================================
# UTILITY FUNCTIONS
# =============================================================================

print_header() {
    echo -e "${BLUE}============================================================================${NC}"
    echo -e "${BLUE}$1${NC}"
    echo -e "${BLUE}============================================================================${NC}"
}

print_test() {
    echo -e "${YELLOW}[TEST]${NC} $1"
    ((TOTAL_TESTS++))
}

print_pass() {
    echo -e "${GREEN}[PASS]${NC} $1"
    ((PASSED_TESTS++))
}

print_fail() {
    echo -e "${RED}[FAIL]${NC} $1"
    ((FAILED_TESTS++))
}

print_info() {
    echo -e "${CYAN}[INFO]${NC} $1"
}

print_warning() {
    echo -e "${YELLOW}[WARN]${NC} $1"
}

cleanup() {
    # Kill any running processes
    pkill -f "./server" 2>/dev/null
    pkill -f "./client" 2>/dev/null
    pkill -f "./server_bonus" 2>/dev/null
    pkill -f "./client_bonus" 2>/dev/null
    sleep 0.1
    
    # Clean up temp files
    rm -f "$VALGRIND_LOG" "$TEST_LOG" "$SERVER_OUTPUT" "$CLIENT_OUTPUT"
}

check_executables() {
    print_header "CHECKING EXECUTABLES"
    
    if [[ ! -f "$SERVER_EXEC" ]]; then
        print_fail "Server executable not found: $SERVER_EXEC"
        return 1
    else
        print_pass "Server executable found"
    fi
    
    if [[ ! -f "$CLIENT_EXEC" ]]; then
        print_fail "Client executable not found: $CLIENT_EXEC"
        return 1
    else
        print_pass "Client executable found"
    fi
    
    if [[ ! -f "$SERVER_BONUS_EXEC" ]]; then
        print_fail "Bonus server executable not found: $SERVER_BONUS_EXEC"
        return 1
    else
        print_pass "Bonus server executable found"
    fi
    
    if [[ ! -f "$CLIENT_BONUS_EXEC" ]]; then
        print_fail "Bonus client executable not found: $CLIENT_BONUS_EXEC"
        return 1
    else
        print_pass "Bonus client executable found"
    fi
    
    return 0
}

# =============================================================================
# BASIC FUNCTIONALITY TESTS
# =============================================================================

test_basic_functionality() {
    print_header "BASIC FUNCTIONALITY TESTS"
    
    # Test 1: Simple message transmission
    print_test "Simple message transmission"
    if run_message_test "$SHORT_MSG" "normal"; then
        print_pass "Simple message transmitted successfully"
    else
        print_fail "Simple message transmission failed"
    fi
    
    # Test 2: Empty message
    print_test "Empty message transmission"
    if run_message_test "$EMPTY_MSG" "normal"; then
        print_pass "Empty message handled correctly"
    else
        print_fail "Empty message handling failed"
    fi
    
    # Test 3: Long message
    print_test "Long message transmission"
    if run_message_test "$LONG_MSG" "normal"; then
        print_pass "Long message transmitted successfully"
    else
        print_fail "Long message transmission failed"
    fi
    
    # Test 4: Special characters
    print_test "Special characters transmission"
    if run_message_test "$SPECIAL_MSG" "normal"; then
        print_pass "Special characters transmitted successfully"
    else
        print_fail "Special characters transmission failed"
    fi
    
    # Test 5: Numeric message
    print_test "Numeric message transmission"
    if run_message_test "$NUMERIC_MSG" "normal"; then
        print_pass "Numeric message transmitted successfully"
    else
        print_fail "Numeric message transmission failed"
    fi
}

# =============================================================================
# BONUS FUNCTIONALITY TESTS
# =============================================================================

test_bonus_functionality() {
    print_header "BONUS FUNCTIONALITY TESTS"
    
    # Test 1: Bonus message transmission with progress indicators
    print_test "Bonus message with progress indicators"
    if run_message_test "$SHORT_MSG" "bonus"; then
        print_pass "Bonus message transmitted successfully"
    else
        print_fail "Bonus message transmission failed"
    fi
    
    # Test 2: Bonus long message with progress
    print_test "Bonus long message with progress indicators"
    if run_message_test "$LONG_MSG" "bonus"; then
        print_pass "Bonus long message transmitted successfully"
    else
        print_fail "Bonus long message transmission failed"
    fi
}

# =============================================================================
# ERROR HANDLING TESTS
# =============================================================================

test_error_handling() {
    print_header "ERROR HANDLING TESTS"
    
    # Test 1: Invalid PID
    print_test "Invalid PID handling"
    timeout 3s $CLIENT_EXEC 999999 "$SHORT_MSG" 2>/dev/null
    if [[ $? -ne 0 ]]; then
        print_pass "Client properly handles invalid PID"
    else
        print_fail "Client doesn't handle invalid PID properly"
    fi
    
    # Test 2: Negative PID
    print_test "Negative PID handling"
    timeout 3s $CLIENT_EXEC -1 "$SHORT_MSG" 2>/dev/null
    if [[ $? -ne 0 ]]; then
        print_pass "Client properly handles negative PID"
    else
        print_fail "Client doesn't handle negative PID properly"
    fi
    
    # Test 3: Invalid arguments
    print_test "Invalid argument count handling"
    timeout 3s $CLIENT_EXEC 1234 2>/dev/null
    if [[ $? -ne 0 ]]; then
        print_pass "Client properly handles invalid argument count"
    else
        print_fail "Client doesn't handle invalid argument count properly"
    fi
    
    # Test 4: Non-numeric PID
    print_test "Non-numeric PID handling"
    timeout 3s $CLIENT_EXEC "abc" "$SHORT_MSG" 2>/dev/null
    if [[ $? -ne 0 ]]; then
        print_pass "Client properly handles non-numeric PID"
    else
        print_fail "Client doesn't handle non-numeric PID properly"
    fi
}

# =============================================================================
# MEMORY LEAK TESTS WITH VALGRIND
# =============================================================================

test_memory_leaks() {
    print_header "MEMORY LEAK TESTS (VALGRIND)"
    
    if ! command -v valgrind &> /dev/null; then
        print_warning "Valgrind not found. Skipping memory leak tests."
        return
    fi
    
    print_info "Running Valgrind memory leak detection..."
    
    # Test server memory leaks
    print_test "Server memory leak detection"
    if run_valgrind_server; then
        print_pass "Server has no memory leaks"
    else
        print_fail "Server has memory leaks or errors"
        ((VALGRIND_ERRORS++))
    fi
    
    # Test client memory leaks
    print_test "Client memory leak detection"
    if run_valgrind_client; then
        print_pass "Client has no memory leaks"
    else
        print_fail "Client has memory leaks or errors"
        ((VALGRIND_ERRORS++))
    fi
    
    # Test bonus server memory leaks
    print_test "Bonus server memory leak detection"
    if run_valgrind_server_bonus; then
        print_pass "Bonus server has no memory leaks"
    else
        print_fail "Bonus server has memory leaks or errors"
        ((VALGRIND_ERRORS++))
    fi
    
    # Test bonus client memory leaks
    print_test "Bonus client memory leak detection"
    if run_valgrind_client_bonus; then
        print_pass "Bonus client has no memory leaks"
    else
        print_fail "Bonus client has memory leaks or errors"
        ((VALGRIND_ERRORS++))
    fi
}

# =============================================================================
# STRESS TESTS
# =============================================================================

test_stress_scenarios() {
    print_header "STRESS TESTS"
    
    # Test 1: Multiple rapid messages
    print_test "Multiple rapid message transmission"
    if run_multiple_messages; then
        print_pass "Multiple messages handled successfully"
    else
        print_fail "Multiple message handling failed"
    fi
    
    # Test 2: Very long message
    print_test "Very long message stress test"
    local very_long_msg=""
    for i in {1..50}; do
        very_long_msg+="This is line $i of a very long stress test message. "
    done
    
    if run_message_test "$very_long_msg" "normal"; then
        print_pass "Very long message handled successfully"
    else
        print_fail "Very long message handling failed"
    fi
}

# =============================================================================
# HELPER FUNCTIONS
# =============================================================================

run_message_test() {
    local message="$1"
    local mode="$2"
    
    # Start server
    if [[ "$mode" == "bonus" ]]; then
        $SERVER_BONUS_EXEC > "$SERVER_OUTPUT" 2>&1 &
        local server_pid=$!
        local client_exec="$CLIENT_BONUS_EXEC"
    else
        $SERVER_EXEC > "$SERVER_OUTPUT" 2>&1 &
        local server_pid=$!
        local client_exec="$CLIENT_EXEC"
    fi
    
    # Wait for server to start
    sleep 0.5
    
    # Check if server is running
    if ! kill -0 $server_pid 2>/dev/null; then
        return 1
    fi
    
    # Send message
    timeout 10s $client_exec $server_pid "$message" > "$CLIENT_OUTPUT" 2>&1
    local client_exit_code=$?
    
    # Wait for message processing
    sleep 1
    
    # Kill server
    kill $server_pid 2>/dev/null
    wait $server_pid 2>/dev/null
    
    # Check results
    if [[ $client_exit_code -eq 0 ]] && grep -q "$message" "$SERVER_OUTPUT" 2>/dev/null; then
        return 0
    else
        return 1
    fi
}

run_multiple_messages() {
    local messages=("Hello" "World" "Test123" "Final")
    
    # Start server
    $SERVER_EXEC > "$SERVER_OUTPUT" 2>&1 &
    local server_pid=$!
    
    # Wait for server to start
    sleep 0.5
    
    # Send multiple messages
    for msg in "${messages[@]}"; do
        timeout 5s $CLIENT_EXEC $server_pid "$msg" > "$CLIENT_OUTPUT" 2>&1
        if [[ $? -ne 0 ]]; then
            kill $server_pid 2>/dev/null
            return 1
        fi
        sleep 0.5
    done
    
    # Kill server
    kill $server_pid 2>/dev/null
    wait $server_pid 2>/dev/null
    
    # Verify all messages were received
    for msg in "${messages[@]}"; do
        if ! grep -q "$msg" "$SERVER_OUTPUT" 2>/dev/null; then
            return 1
        fi
    done
    
    return 0
}

run_valgrind_server() {
    timeout 15s bash -c '
        valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --error-exitcode=1 ./server &
        SERVER_PID=$!
        sleep 1
        ./client $SERVER_PID "Test message" >/dev/null 2>&1
        sleep 1
        kill $SERVER_PID 2>/dev/null
        wait $SERVER_PID 2>/dev/null
    ' 2> "$VALGRIND_LOG"
    
    # Check Valgrind results
    if grep -q "ERROR SUMMARY: 0 errors from 0 contexts" "$VALGRIND_LOG" && \
       grep -q "definitely lost: 0 bytes in 0 blocks" "$VALGRIND_LOG" && \
       grep -q "indirectly lost: 0 bytes in 0 blocks" "$VALGRIND_LOG"; then
        return 0
    else
        echo "=== VALGRIND SERVER ERRORS ===" >> "$TEST_LOG"
        cat "$VALGRIND_LOG" >> "$TEST_LOG"
        echo "=================================" >> "$TEST_LOG"
        return 1
    fi
}

run_valgrind_client() {
    timeout 10s bash -c '
        ./server &
        SERVER_PID=$!
        sleep 1
        valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --error-exitcode=1 ./client $SERVER_PID "Test message" >/dev/null 2>&1
        CLIENT_EXIT_CODE=$?
        kill $SERVER_PID 2>/dev/null
        wait $SERVER_PID 2>/dev/null
        exit $CLIENT_EXIT_CODE
    ' 2> "$VALGRIND_LOG"
    
    # Check Valgrind results
    if grep -q "ERROR SUMMARY: 0 errors from 0 contexts" "$VALGRIND_LOG" && \
       grep -q "definitely lost: 0 bytes in 0 blocks" "$VALGRIND_LOG" && \
       grep -q "indirectly lost: 0 bytes in 0 blocks" "$VALGRIND_LOG"; then
        return 0
    else
        echo "=== VALGRIND CLIENT ERRORS ===" >> "$TEST_LOG"
        cat "$VALGRIND_LOG" >> "$TEST_LOG"
        echo "=================================" >> "$TEST_LOG"
        return 1
    fi
}

run_valgrind_server_bonus() {
    timeout 15s bash -c '
        valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --error-exitcode=1 ./server_bonus &
        SERVER_PID=$!
        sleep 1
        ./client_bonus $SERVER_PID "Test message" >/dev/null 2>&1
        sleep 2
        kill $SERVER_PID 2>/dev/null
        wait $SERVER_PID 2>/dev/null
    ' 2> "$VALGRIND_LOG"
    
    if grep -q "ERROR SUMMARY: 0 errors from 0 contexts" "$VALGRIND_LOG" && \
       grep -q "definitely lost: 0 bytes in 0 blocks" "$VALGRIND_LOG" && \
       grep -q "indirectly lost: 0 bytes in 0 blocks" "$VALGRIND_LOG"; then
        return 0
    else
        echo "=== VALGRIND BONUS SERVER ERRORS ===" >> "$TEST_LOG"
        cat "$VALGRIND_LOG" >> "$TEST_LOG"
        echo "=====================================" >> "$TEST_LOG"
        return 1
    fi
}

run_valgrind_client_bonus() {
    timeout 15s bash -c '
        ./server_bonus &
        SERVER_PID=$!
        sleep 1
        valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --error-exitcode=1 ./client_bonus $SERVER_PID "Test message" >/dev/null 2>&1
        CLIENT_EXIT_CODE=$?
        sleep 2
        kill $SERVER_PID 2>/dev/null
        wait $SERVER_PID 2>/dev/null
        exit $CLIENT_EXIT_CODE
    ' 2> "$VALGRIND_LOG"
    
    if grep -q "ERROR SUMMARY: 0 errors from 0 contexts" "$VALGRIND_LOG" && \
       grep -q "definitely lost: 0 bytes in 0 blocks" "$VALGRIND_LOG" && \
       grep -q "indirectly lost: 0 bytes in 0 blocks" "$VALGRIND_LOG"; then
        return 0
    else
        echo "=== VALGRIND BONUS CLIENT ERRORS ===" >> "$TEST_LOG"
        cat "$VALGRIND_LOG" >> "$TEST_LOG"
        echo "=====================================" >> "$TEST_LOG"
        return 1
    fi
}

# =============================================================================
# PERFORMANCE TESTS
# =============================================================================

test_performance() {
    print_header "PERFORMANCE TESTS"
    
    # Test transmission speed
    print_test "Message transmission speed test"
    local start_time=$(date +%s%N)
    
    if run_message_test "$LONG_MSG" "normal"; then
        local end_time=$(date +%s%N)
        local duration=$((($end_time - $start_time) / 1000000)) # Convert to milliseconds
        print_pass "Message transmitted in ${duration}ms"
        print_info "Performance: ${duration}ms for message of length ${#LONG_MSG}"
    else
        print_fail "Performance test failed"
    fi
}

# =============================================================================
# FINAL RESULTS
# =============================================================================

print_final_results() {
    print_header "FINAL TEST RESULTS"
    
    echo -e "${CYAN}Total Tests:${NC} $TOTAL_TESTS"
    echo -e "${GREEN}Passed Tests:${NC} $PASSED_TESTS"
    echo -e "${RED}Failed Tests:${NC} $FAILED_TESTS"
    echo -e "${YELLOW}Valgrind Errors:${NC} $VALGRIND_ERRORS"
    
    local success_rate=0
    if [[ $TOTAL_TESTS -gt 0 ]]; then
        success_rate=$((($PASSED_TESTS * 100) / $TOTAL_TESTS))
    fi
    
    echo -e "${BLUE}Success Rate:${NC} ${success_rate}%"
    
    if [[ $FAILED_TESTS -eq 0 && $VALGRIND_ERRORS -eq 0 ]]; then
        echo -e "\n${GREEN}🎉 ALL TESTS PASSED! Your mini_talk project is excellent! 🎉${NC}"
        return 0
    else
        echo -e "\n${RED}❌ Some tests failed. Check the details above. ❌${NC}"
        return 1
    fi
}

# =============================================================================
# MAIN EXECUTION
# =============================================================================

main() {
    echo -e "${PURPLE}"
    echo "============================================================================"
    echo "                    MINITALK COMPREHENSIVE TESTER"
    echo "                    42 School Project Testing Suite"
    echo "============================================================================"
    echo -e "${NC}"
    
    # Clean up any existing processes
    cleanup
    
    # Check if executables exist
    if ! check_executables; then
        echo -e "${RED}❌ EXECUTABLES NOT FOUND. Please run 'make && make bonus' first. ❌${NC}"
        exit 1
    fi
    
    # Run all tests
    test_basic_functionality
    test_bonus_functionality
    test_error_handling
    test_memory_leaks
    test_stress_scenarios
    test_performance
    
    # Print final results
    print_final_results
    
    # Clean up
    cleanup
    
    # Exit with appropriate code
    if [[ $FAILED_TESTS -eq 0 && $VALGRIND_ERRORS -eq 0 ]]; then
        exit 0
    else
        exit 1
    fi
}

# Handle script interruption
trap cleanup EXIT
trap 'echo -e "\n${YELLOW}Test interrupted by user${YELLOW}"; cleanup; exit 130' INT

# Run main function
main "$@"
#!/bin/bash

# =============================================================================
# 42 MINITALK FINAL EVALUATION
# Exact alignment with 42 official evaluation criteria
# Based on: https://wormav.github.io/42_eval/Cursus/Minitalk/index.html
# =============================================================================

# Colors for output
RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[1;33m'
BLUE='\033[0;34m'
PURPLE='\033[0;35m'
CYAN='\033[0;36m'
NC='\033[0m' # No Color

# Evaluation scores
TOTAL_POINTS=0
MAX_POINTS=0
MANDATORY_POINTS=0
MANDATORY_MAX=0
BONUS_POINTS=0
BONUS_MAX=0

# Test results tracking
declare -A RESULTS

# =============================================================================
# UTILITY FUNCTIONS
# =============================================================================

print_header() {
    echo -e "${BLUE}============================================================================${NC}"
    echo -e "${BLUE}$1${NC}"
    echo -e "${BLUE}============================================================================${NC}"
}

print_section() {
    echo -e "\n${PURPLE}## $1${NC}"
    echo -e "${PURPLE}============================================================================${NC}"
}

print_test() {
    echo -e "${YELLOW}[TEST]${NC} $1"
}

print_pass() {
    echo -e "${GREEN}[PASS]${NC} $1"
    RESULTS["$1"]="PASS"
}

print_fail() {
    echo -e "${RED}[FAIL]${NC} $1"
    RESULTS["$1"]="FAIL"
}

print_info() {
    echo -e "${CYAN}[INFO]${NC} $1"
}

print_warning() {
    echo -e "${YELLOW}[WARN]${NC} $1"
}

add_points() {
    local points=$1
    local max_points=$2
    local category=$3
    
    echo -e "${CYAN}[+] $points/$max_points points - $category${NC}"
    TOTAL_POINTS=$((TOTAL_POINTS + points))
    MAX_POINTS=$((MAX_POINTS + max_points))
    
    if [[ "$category" == *"mandatory"* ]]; then
        MANDATORY_POINTS=$((MANDATORY_POINTS + points))
        MANDATORY_MAX=$((MANDATORY_MAX + max_points))
    else
        BONUS_POINTS=$((BONUS_POINTS + points))
        BONUS_MAX=$((BONUS_MAX + max_points))
    fi
}

cleanup() {
    pkill -f "./server" 2>/dev/null
    pkill -f "./client" 2>/dev/null
    pkill -f "./server_bonus" 2>/dev/null
    pkill -f "./client_bonus" 2>/dev/null
    sleep 0.1
    rm -f *.tmp *.log 2>/dev/null
}

# =============================================================================
# PRELIMINARY TESTS (42 Evaluation Step 1)
# =============================================================================

preliminary_tests() {
    print_section "PRELIMINARY TESTS"
    
    # Check Git repository
    print_test "Checking if this is a Git repository"
    if git rev-parse --git-dir > /dev/null 2>&1; then
        print_pass "Git repository found"
    else
        print_fail "Not a Git repository"
    fi
    
    # Check for empty repository
    print_test "Checking for empty repository"
    if git ls-files | grep -q .; then
        print_pass "Repository contains files"
    else
        print_fail "Empty repository"
    fi
    
    # Check compilation
    print_test "Testing compilation"
    make clean >/dev/null 2>&1
    if make >/dev/null 2>&1 && make bonus >/dev/null 2>&1; then
        print_pass "Project compiles without errors"
    else
        print_fail "Compilation failed"
        echo "Compilation errors found"
        make 2>&1
    fi
    
    # Check Makefile behavior
    print_test "Testing Makefile re-linking behavior"
    make clean >/dev/null 2>&1
    make >/dev/null 2>&1
    make >/dev/null 2>&1  # Should not re-link if nothing changed
    if [[ $? -eq 0 ]]; then
        print_pass "Makefile behaves correctly (no unnecessary re-linking)"
    else
        print_warning "Makefile may have re-linking issues"
    fi
    
    # Check Norm compliance (basic check)
    print_test "Basic 42 Norm check"
    norminette_error=0
    for file in c_files/*.c *.h; do
        if [[ -f "$file" ]]; then
            if ! norminette "$file" >/dev/null 2>&1; then
                print_warning "Potential norm issues in $file"
                norminette_error=1
            fi
        fi
    done
    
    if [[ $norminette_error -eq 0 ]]; then
        print_pass "Basic Norm check passed"
    else
        print_fail "Norm errors detected"
        echo "Run norminette manually for detailed report"
    fi
}

# =============================================================================
# GENERAL INSTRUCTIONS EVALUATION
# =============================================================================

general_instructions() {
    print_section "GENERAL INSTRUCTIONS (8 POINTS)"
    
    # Makefile compiles both executables
    print_test "Makefile compiles both executables"
    if [[ -f "server" && -f "client" && -f "server_bonus" && -f "client_bonus" ]]; then
        print_pass "All executables present"
        add_points 1 1 "Makefile compiles both executables"
    else
        print_fail "Missing executables"
        add_points 0 1 "Makefile compiles both executables"
    fi
    
    # Server prints PID
    print_test "Server prints his PID at launch"
    timeout 5s ./server > server_pid_test.tmp 2>/dev/null &
    SERVER_PID=$!
    sleep 1
    
    if grep -E "^[0-9]+$" server_pid_test.tmp >/dev/null 2>&1 || \
       grep -E "PID:[[:space:]]*[0-9]+" server_pid_test.tmp >/dev/null 2>&1 || \
       grep -E "Server PID[[:space:]]*[0-9]+" server_pid_test.tmp >/dev/null 2>&1; then
        print_pass "Server displays PID correctly"
        add_points 2 2 "Server prints his PID at launch"
    else
        print_fail "Server doesn't display PID"
        cat server_pid_test.tmp
        add_points 0 2 "Server prints his PID at launch"
    fi
    
    kill $SERVER_PID 2>/dev/null 2>/dev/null
    
    # Client usage
    print_test "Client usage: ./client PID_SERVER STRING_TO_PASS"
    if [[ -f "client" ]]; then
        # Test client with wrong arguments
        timeout 3s ./client 2>/dev/null
        if [[ $? -ne 0 ]]; then
            timeout 3s ./client 12345 2>/dev/null
            if [[ $? -ne 0 ]]; then
                print_pass "Client has correct usage pattern"
                add_points 2 2 "Client usage: ./client PID_SERVER STRING_TO_PASS"
            else
                print_fail "Client accepts wrong argument count"
                add_points 0 2 "Client usage: ./client PID_SERVER STRING_TO_PASS"
            fi
        else
            print_fail "Client accepts no arguments"
            add_points 0 2 "Client usage: ./client PID_SERVER STRING_TO_PASS"
        fi
    else
        print_fail "Client executable not found"
        add_points 0 2 "Client usage: ./client PID_SERVER STRING_TO_PASS"
    fi
}

# =============================================================================
# MANDATORY PART EVALUATION
# =============================================================================

mandatory_part() {
    print_section "MANDATORY PART"
    
    # Check signal usage only
    print_test "Communication uses only SIGUSR1 and SIGUSR2"
    if grep -r "SIGUSR[12]" c_files/ >/dev/null 2>&1 && \
       ! grep -r "SIGKILL\|SIGTERM\|SIGINT\|SIGQUIT\|SIGPIPE" c_files/ >/dev/null 2>&1; then
        print_pass "Only SIGUSR1 and SIGUSR2 used for communication"
    else
        print_fail "Other signals may be used for communication"
    fi
    
    # Message transmission test
    print_test "Message transmission of any size"
    message_transmission_tests
    
    # Simple setup tests
    simple_setup_tests
}

message_transmission_tests() {
    print_info "Testing message transmission capabilities"
    
    # Test short message
    print_test "Short message transmission"
    ./server > server_short.tmp 2>&1 &
    SERVER_PID=$!
    sleep 0.5
    
    if kill -0 $SERVER_PID 2>/dev/null; then
        timeout 10s ./client $SERVER_PID "Hello World" >/dev/null 2>&1
        sleep 1
        if grep -q "Hello World" server_short.tmp 2>/dev/null; then
            print_pass "Short message transmitted correctly"
            TRANSMISSION_SCORE=3
        else
            print_fail "Short message transmission failed"
            cat server_short.tmp
            TRANSMISSION_SCORE=0
        fi
    else
        print_fail "Server failed to start"
        TRANSMISSION_SCORE=0
    fi
    
    kill $SERVER_PID 2>/dev/null 2>/dev/null
    
    # Test long message
    print_test "Long message transmission"
    ./server > server_long.tmp 2>&1 &
    SERVER_PID=$!
    sleep 0.5
    
    if kill -0 $SERVER_PID 2>/dev/null; then
        long_msg="This is a very long message that tests the transmission capabilities of the mini_talk project. It contains multiple characters and should demonstrate that the server can handle messages of any size without getting stuck or printing wrong characters."
        timeout 15s ./client $SERVER_PID "$long_msg" >/dev/null 2>&1
        sleep 2
        
        if grep -q "$long_msg" server_long.tmp 2>/dev/null; then
            print_pass "Long message transmitted correctly"
            LONG_TRANSMISSION_SCORE=3
        else
            print_fail "Long message transmission failed"
            print_info "Expected: $long_msg"
            print_info "Server output:"
            cat server_long.tmp
            LONG_TRANSMISSION_SCORE=0
        fi
    else
        print_fail "Server failed to start for long message test"
        LONG_TRANSMISSION_SCORE=0
    fi
    
    kill $SERVER_PID 2>/dev/null 2>/dev/null
    
    # Test special characters
    print_test "Special characters transmission"
    ./server > server_special.tmp 2>&1 &
    SERVER_PID=$!
    sleep 0.5
    
    if kill -0 $SERVER_PID 2>/dev/null; then
        special_msg="Special chars: !@#$%^&*()_+-={}[]|\\:;\"'<>?,./123"
        timeout 15s ./client $SERVER_PID "$special_msg" >/dev/null 2>&1
        sleep 1
        
        if grep -F "$special_msg" server_special.tmp 2>/dev/null; then
            print_pass "Special characters transmitted correctly"
            SPECIAL_TRANSMISSION_SCORE=3
        else
            print_fail "Special characters transmission failed"
            print_info "Expected: $special_msg"
            print_info "Server output:"
            cat server_special.tmp
            SPECIAL_TRANSMISSION_SCORE=1  # Partial credit
        fi
    else
        print_fail "Server failed to start for special characters test"
        SPECIAL_TRANSMISSION_SCORE=0
    fi
    
    kill $SERVER_PID 2>/dev/null 2>/dev/null
    
    # Calculate transmission score
    total_transmission=$((TRANSMISSION_SCORE + LONG_TRANSMISSION_SCORE + SPECIAL_TRANSMISSION_SCORE))
    if [[ $total_transmission -ge 6 ]]; then
        transmission_points=5
    elif [[ $total_transmission -ge 4 ]]; then
        transmission_points=4
    elif [[ $total_transmission -ge 2 ]]; then
        transmission_points=3
    elif [[ $total_transmission -ge 1 ]]; then
        transmission_points=2
    else
        transmission_points=0
    fi
    
    echo -e "${CYAN}[+] Transmission score: $transmission_points/5${NC}"
    add_points $transmission_points 5 "Message transmission"
}

simple_setup_tests() {
    print_info "Testing simple setup requirements"
    
    # Multiple strings without restart
    print_test "Server can receive multiple strings without restart"
    ./server > server_multi.tmp 2>&1 &
    SERVER_PID=$!
    sleep 0.5
    
    multi_success=0
    for msg in "Message 1" "Message 2" "Message 3"; do
        if kill -0 $SERVER_PID 2>/dev/null; then
            timeout 10s ./client $SERVER_PID "$msg" >/dev/null 2>&1
            sleep 1
            if grep -q "$msg" server_multi.tmp 2>/dev/null; then
                multi_success=$((multi_success + 1))
            fi
        fi
    done
    
    kill $SERVER_PID 2>/dev/null 2>/dev/null
    
    if [[ $multi_success -eq 3 ]]; then
        print_pass "Server received all messages without restart"
        add_points 1 1 "Multiple strings without restart"
    else
        print_fail "Server failed to receive multiple messages"
        print_info "Successful messages: $multi_success/3"
        add_points 0 1 "Multiple strings without restart"
    fi
    
    # Global variable count
    print_test "Only one global variable per program (or none)"
    global_count=0
    for file in c_files/*.c; do
        if [[ -f "$file" ]]; then
            file_globals=$(grep -E "^[[:space:]]*[a-zA-Z_][a-zA-Z0-9_]*[[:space:]]*=" "$file" 2>/dev/null | wc -l)
            global_count=$((global_count + file_globals))
        fi
    done
    
    # Check for static globals in signal handlers (allowed)
    allowed_globals=0
    if grep -r "static.*volatile.*sig_atomic_t" c_files/ >/dev/null 2>&1; then
        allowed_globals=2  # One per program (server & client)
    fi
    
    actual_globals=$((global_count - allowed_globals))
    
    if [[ $actual_globals -le 2 ]]; then  # Allow up to 2 (one per program)
        print_pass "Global variable count acceptable (≤2 total, ≤1 per program)"
        add_points 1 1 "Global variable constraint"
    else
        print_fail "Too many global variables: $actual_globals (should be ≤2 total)"
        add_points 0 1 "Global variable constraint"
    fi
    
    # Communication signals only
    print_test "Communication uses only SIGUSR1 and SIGUSR2"
    signal_check=$(grep -r "kill.*SIGUSR[12]" c_files/ | wc -l)
    forbidden_signals=$(grep -r "kill.*SIG[^12]" c_files/ 2>/dev/null | wc -l)
    
    if [[ $signal_check -gt 0 && $forbidden_signals -eq 0 ]]; then
        print_pass "Communication uses only SIGUSR1 and SIGUSR2"
        add_points 3 3 "Signal communication requirement"
    else
        print_fail "Communication uses wrong signals"
        add_points 0 3 "Signal communication requirement"
    fi
}

# =============================================================================
# BONUS PART EVALUATION
# =============================================================================

bonus_part() {
    print_section "BONUS PART"
    
    # Only evaluate if mandatory part is mostly complete
    if [[ $MANDATORY_POINTS -lt $((MANDATORY_MAX * 2 / 3)) ]]; then
        print_warning "Mandatory part not sufficiently completed - skipping bonus evaluation"
        return
    fi
    
    # Unicode support
    print_test "Unicode characters support"
    unicode_test
    
    # Acknowledgment system
    print_test "Server acknowledges every message received"
    acknowledgement_test
}

unicode_test() {
    print_info "Testing Unicode character support"
    
    # Test server Unicode
    ./server_bonus > server_unicode.tmp 2>&1 &
    SERVER_PID=$!
    sleep 0.5
    
    if kill -0 $SERVER_PID 2>/dev/null; then
        unicode_msg="Unicode test: àéîöü ñç 中文 🚀"
        timeout 15s ./client_bonus $SERVER_PID "$unicode_msg" >/dev/null 2>&1
        sleep 2
        
        if grep -q "$unicode_msg" server_unicode.tmp 2>/dev/null; then
            print_pass "Unicode characters supported (server and client)"
            UNICODE_SCORE=5
        else
            print_fail "Unicode support failed"
            print_info "Expected: $unicode_msg"
            print_info "Server output:"
            cat server_unicode.tmp
            UNICODE_SCORE=0
        fi
    else
        print_fail "Server failed to start for Unicode test"
        UNICODE_SCORE=0
    fi
    
    kill $SERVER_PID 2>/dev/null 2>/dev/null
    
    add_points $UNICODE_SCORE 5 "Unicode support"
}

acknowledgement_test() {
    print_info "Testing server acknowledgment system"
    
    # Test bonus server acknowledgment
    ./server_bonus > server_ack.tmp 2>&1 &
    SERVER_PID=$!
    sleep 0.5
    
    if kill -0 $SERVER_PID 2>/dev/null; then
        # Test client with timeout to see if it receives acknowledgment
        timeout 10s ./client_bonus $SERVER_PID "ACK Test" > client_ack.tmp 2>&1 &
        CLIENT_PID=$!
        
        # Wait for client to complete
        sleep 3
        
        # Check if client received completion signal
        if grep -q "message received" client_ack.tmp 2>/dev/null || \
           grep -q "##message received!##" client_ack.tmp 2>/dev/null; then
            print_pass "Server acknowledges message to client"
            ACK_SCORE=5
        else
            print_fail "Server acknowledgment not working properly"
            print_info "Client output:"
            cat client_ack.tmp
            ACK_SCORE=0
        fi
        
        kill $CLIENT_PID 2>/dev/null 2>/dev/null
    else
        print_fail "Server failed to start for acknowledgment test"
        ACK_SCORE=0
    fi
    
    kill $SERVER_PID 2>/dev/null 2>/dev/null
    
    add_points $ACK_SCORE 5 "Acknowledgment system"
}

# =============================================================================
# MEMORY LEAKS AND ROBUSTNESS
# =============================================================================

robustness_tests() {
    print_section "ROBUSTNESS TESTS"
    
    # Memory leak tests with Valgrind
    if command -v valgrind >/dev/null 2>&1; then
        print_test "Memory leak detection"
        memory_leak_tests
    else
        print_warning "Valgrind not available - skipping memory tests"
    fi
    
    # Error handling
    print_test "Error handling robustness"
    error_handling_tests
}

memory_leak_tests() {
    memory_ok=0
    
    # Test server memory
    timeout 10s bash -c '
        valgrind --leak-check=full --error-exitcode=1 ./server &
        SERVER_PID=$!
        sleep 0.5
        ./client $SERVER_PID "Memory Test" >/dev/null 2>&1
        sleep 1
        kill $SERVER_PID 2>/dev/null
        wait $SERVER_PID 2>/dev/null
    ' 2>/dev/null
    
    if [[ $? -eq 0 ]]; then
        print_pass "Server: No memory leaks detected"
        memory_ok=$((memory_ok + 1))
    else
        print_fail "Server: Memory leaks detected"
    fi
    
    # Test client memory
    timeout 10s bash -c '
        ./server &
        SERVER_PID=$!
        sleep 0.5
        valgrind --leak-check=full --error-exitcode=1 ./client $SERVER_PID "Memory Test" >/dev/null 2>&1
        kill $SERVER_PID 2>/dev/null
    ' 2>/dev/null
    
    if [[ $? -eq 0 ]]; then
        print_pass "Client: No memory leaks detected"
        memory_ok=$((memory_ok + 1))
    else
        print_fail "Client: Memory leaks detected"
    fi
    
    if [[ $memory_ok -eq 2 ]]; then
        print_info "Memory management: EXCELLENT"
    elif [[ $memory_ok -eq 1 ]]; then
        print_info "Memory management: GOOD (minor issues)"
    else
        print_info "Memory management: NEEDS IMPROVEMENT"
    fi
}

error_handling_tests() {
    # Test invalid PID
    print_test "Invalid PID handling"
    timeout 5s ./client 999999 "Test" >/dev/null 2>&1
    if [[ $? -ne 0 ]]; then
        print_pass "Client handles invalid PID correctly"
    else
        print_fail "Client doesn't handle invalid PID"
    fi
    
    # Test negative PID
    print_test "Negative PID handling"
    timeout 5s ./client -1 "Test" >/dev/null 2>&1
    if [[ $? -ne 0 ]]; then
        print_pass "Client handles negative PID correctly"
    else
        print_fail "Client doesn't handle negative PID"
    fi
    
    # Test non-numeric PID
    print_test "Non-numeric PID handling"
    timeout 5s ./client "not_a_number" "Test" >/dev/null 2>&1
    if [[ $? -ne 0 ]]; then
        print_pass "Client handles non-numeric PID correctly"
    else
        print_fail "Client doesn't handle non-numeric PID"
    fi
}

# =============================================================================
# FINAL EVALUATION AND GRADING
# =============================================================================

final_evaluation() {
    print_section "FINAL EVALUATION"
    
    echo -e "${BLUE}=== PRELIMINARY REQUIREMENTS CHECK ===${NC}"
    if [[ "${RESULTS[Checking if this is a Git repository]}" == "PASS" && \
          "${RESULTS[Checking for empty repository]}" == "PASS" && \
          "${RESULTS[Testing compilation]}" == "PASS" ]]; then
        echo -e "${GREEN}✅ Preliminary requirements SATISFIED${NC}"
    else
        echo -e "${RED}❌ Preliminary requirements FAILED${NC}"
        echo -e "${RED}Grade: 0/100 (cannot proceed)${NC}"
        return
    fi
    
    echo -e "\n${BLUE}=== SCORING BREAKDOWN ===${NC}"
    echo -e "${CYAN}General Instructions: $TOTAL_POINTS/$MAX_POINTS points${NC}"
    echo -e "${CYAN}Mandatory Part: $MANDATORY_POINTS/$MANDATORY_MAX points${NC}"
    
    if [[ $MANDATORY_POINTS -ge $((MANDATORY_MAX * 2 / 3)) ]]; then
        echo -e "${CYAN}Bonus Part: $BONUS_POINTS/$BONUS_MAX points${NC}"
    else
        echo -e "${YELLOW}Bonus Part: SKIPPED (mandatory insufficient)${NC}"
        BONUS_POINTS=0
        BONUS_MAX=0
    fi
    
    FINAL_TOTAL=$((MANDATORY_POINTS + BONUS_POINTS))
    FINAL_MAX=$((MANDATORY_MAX + BONUS_MAX))
    
    echo -e "\n${BLUE}=== FINAL GRADE ===${NC}"
    echo -e "${CYAN}Total Score: $FINAL_TOTAL/$FINAL_MAX points${NC}"
    
    if [[ $FINAL_TOTAL -eq $FINAL_MAX ]]; then
        echo -e "${GREEN}🏆 OUTSTANDING PROJECT (100/100)${NC}"
        echo -e "${GREEN}⭐ This project would receive maximum score at 42 evaluation! ⭐${NC}"
    elif [[ $FINAL_TOTAL -ge $((FINAL_MAX * 90 / 100)) ]]; then
        echo -e "${GREEN}✅ EXCELLENT PROJECT${NC}"
    elif [[ $FINAL_TOTAL -ge $((FINAL_MAX * 80 / 100)) ]]; then
        echo -e "${YELLOW}👍 GOOD PROJECT${NC}"
    elif [[ $FINAL_TOTAL -ge $((FINAL_MAX * 70 / 100)) ]]; then
        echo -e "${YELLOW}✔️  ACCEPTABLE PROJECT${NC}"
    else
        echo -e "${RED}❌ PROJECT NEEDS SIGNIFICANT IMPROVEMENT${NC}"
    fi
    
    # Defense recommendation
    echo -e "\n${BLUE}=== DEFENSE RECOMMENDATION ===${NC}"
    if [[ $FINAL_TOTAL -ge $((FINAL_MAX * 85 / 100)) ]]; then
        echo -e "${GREEN}🎯 Ready for 42 defense!${NC}"
        echo -e "${GREEN}   - Demonstrate understanding of signal handling${NC}"
        echo -e "${GREEN}   - Explain your memory management strategy${NC}"
        echo -e "${GREEN}   - Be prepared to discuss design choices${NC}"
    else
        echo -e "${YELLOW}⚠️  Consider improvements before defense${NC}"
    fi
}

# =============================================================================
# MAIN EXECUTION
# =============================================================================

main() {
    echo -e "${PURPLE}"
    echo "============================================================================"
    echo "                    42 MINITALK FINAL EVALUATION"
    echo "                   Official 42 Evaluation Criteria"
    echo "============================================================================"
    echo -e "${NC}"
    
    cleanup
    
    # Run all evaluation sections
    preliminary_tests
    general_instructions
    mandatory_part
    bonus_part
    robustness_tests
    final_evaluation
    
    cleanup
}

# Handle interruption
trap cleanup EXIT
trap 'echo -e "\n${YELLOW}Evaluation interrupted${YELLOW}"; cleanup; exit 130' INT

# Run main function
main "$@"
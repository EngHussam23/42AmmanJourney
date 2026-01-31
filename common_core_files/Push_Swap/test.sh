#!/bin/bash

RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[1;33m'
NC='\033[0m' # No Color

echo "========================================="
echo "   PUSH_SWAP COMPREHENSIVE TEST SUITE"
echo "========================================="

# Test counter
PASSED=0
FAILED=0

# Function to test and verify
test_case() {
    NAME=$1
    ARGS=$2
    MAX_OPS=$3
    
    # Run push_swap
    RESULT=$(./push_swap $ARGS 2>&1)
    
    # Check for errors in output
    if echo "$RESULT" | grep -q "Error"; then
        echo -e "${RED}[FAIL]${NC} $NAME - Got Error output"
        ((FAILED++))
        return
    fi
    
    # Count operations
    OPS=$(echo "$RESULT" | wc -l)
    
    # Check with checker
    CHECK=$(echo "$RESULT" | ./checker_linux $ARGS 2>&1)
    
    if [ "$CHECK" = "OK" ]; then
        if [ -z "$MAX_OPS" ] || [ "$OPS" -le "$MAX_OPS" ]; then
            echo -e "${GREEN}[PASS]${NC} $NAME - $OPS operations"
            ((PASSED++))
        else
            echo -e "${YELLOW}[WARN]${NC} $NAME - $OPS ops (expected ≤ $MAX_OPS)"
            ((PASSED++))
        fi
    elif [ "$CHECK" = "KO" ]; then
        echo -e "${RED}[FAIL]${NC} $NAME - Checker returned KO"
        ((FAILED++))
    else
        echo -e "${RED}[FAIL]${NC} $NAME - Checker error: $CHECK"
        ((FAILED++))
    fi
}

# Function to test error cases
test_error() {
    NAME=$1
    shift
    ARGS="$@"
    
    RESULT=$(./push_swap $ARGS 2>&1)
    
    if echo "$RESULT" | grep -q "Error"; then
        echo -e "${GREEN}[PASS]${NC} $NAME - Correctly returned Error"
        ((PASSED++))
    else
        echo -e "${RED}[FAIL]${NC} $NAME - Should have returned Error"
        ((FAILED++))
    fi
}

# Function to test no output cases
test_no_output() {
    NAME=$1
    shift
    ARGS="$@"
    
    RESULT=$(./push_swap $ARGS 2>&1)
    
    if [ -z "$RESULT" ]; then
        echo -e "${GREEN}[PASS]${NC} $NAME - Correctly returned no output"
        ((PASSED++))
    else
        echo -e "${RED}[FAIL]${NC} $NAME - Should have no output"
        ((FAILED++))
    fi
}

echo ""
echo "=== EDGE CASES ==="
test_no_output "No arguments" 
test_no_output "Already sorted (2)" "1 2"
test_no_output "Already sorted (3)" "1 2 3"
test_no_output "Already sorted (5)" "1 2 3 4 5"
test_no_output "Single number" "42"

echo ""
echo "=== ERROR CASES ==="
test_error "Duplicate numbers" "1 2 3 2"
test_error "Non-numeric" "1 2 abc"
test_error "Overflow INT_MAX" "2147483648"
test_error "Overflow INT_MIN" "-2147483649"
test_error "Empty string" ""
test_error "Only spaces" "   "
test_error "Invalid sign placement" "1 2+ 3"
test_error "Double sign" "++5"
test_error "Double sign negative" "--5"
test_error "Sign only" "+"
test_error "Multiple duplicates" "5 5 5"

echo ""
echo "=== BASIC SORTING ==="
test_case "2 numbers (reverse)" "2 1" 1
test_case "2 numbers (random)" "5 3" 1
test_case "3 numbers (reverse)" "3 2 1" 3
test_case "3 numbers (random 1)" "2 3 1" 3
test_case "3 numbers (random 2)" "3 1 2" 3
test_case "4 numbers" "4 3 2 1" 12
test_case "5 numbers (reverse)" "5 4 3 2 1" 12
test_case "5 numbers (random)" "3 5 1 4 2" 12

echo ""
echo "=== WITH QUOTES ==="
test_case "Quoted string (3)" "\"3 2 1\"" 3
test_case "Quoted string (5)" "\"5 4 3 2 1\"" 12
test_case "Mixed format" "5 \"4 3\" 2 1" 12

echo ""
echo "=== NEGATIVE NUMBERS ==="
test_case "All negative" "-5 -2 -8 -1" 12
test_case "Mixed positive/negative" "-5 3 -1 0 2" 12
test_case "INT_MIN and INT_MAX" "2147483647 -2147483648 0" 3

echo ""
echo "=== SIGNS ==="
test_case "Positive sign" "+5 +3 +1" 3
test_case "Mixed signs" "+5 -3 1" 3
test_case "Zero with sign" "+0 -1 1" 3

echo ""
echo "=== MEDIUM SETS ==="
test_case "10 numbers" "$(shuf -i 1-10 -n 10 | tr '\n' ' ')"
test_case "25 numbers" "$(shuf -i 1-25 -n 25 | tr '\n' ' ')"
test_case "50 numbers" "$(shuf -i 1-50 -n 50 | tr '\n' ' ')"

echo ""
echo "=== LARGE SETS (Performance) ==="
ARG100=$(shuf -i 1-100 -n 100 | tr '\n' ' ')
test_case "100 numbers" "$ARG100" 700

ARG500=$(shuf -i 1-500 -n 500 | tr '\n' ' ')
test_case "500 numbers" "$ARG500" 5500

echo ""
echo "=== SPECIAL PATTERNS ==="
test_case "Descending order (10)" "10 9 8 7 6 5 4 3 2 1"
test_case "Almost sorted" "1 2 3 5 4"
test_case "Rotated" "3 4 5 1 2"

echo ""
echo "========================================="
echo "   TEST SUMMARY"
echo "========================================="
echo -e "${GREEN}PASSED: $PASSED${NC}"
echo -e "${RED}FAILED: $FAILED${NC}"
TOTAL=$((PASSED + FAILED))
echo "TOTAL: $TOTAL"

if [ $FAILED -eq 0 ]; then
    echo -e "${GREEN}ALL TESTS PASSED!${NC}"
    exit 0
else
    echo -e "${RED}SOME TESTS FAILED!${NC}"
    exit 1
fi
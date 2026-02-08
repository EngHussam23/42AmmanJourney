# MiniTalk Comprehensive Tester

## 🎯 Purpose

This comprehensive testing suite validates your mini_talk project according to 42 school standards, including:
- Basic functionality testing
- Bonus features validation  
- Memory leak detection with Valgrind
- Error handling verification
- Stress testing and performance analysis

## 🚀 Usage

```bash
# Make sure your project is compiled
make && make bonus

# Run the comprehensive test suite
./mini_talk_tester.sh
```

## 📋 Test Categories

### ✅ Basic Functionality Tests
- Simple message transmission
- Empty message handling
- Long message transmission
- Special characters
- Numeric messages

### ✅ Bonus Functionality Tests
- Progress indicators
- Enhanced confirmation system
- Client-server acknowledgments

### ✅ Error Handling Tests
- Invalid PID validation
- Negative PID handling
- Argument count validation
- Non-numeric PID handling

### ✅ Memory Leak Tests (Valgrind)
- Server memory leak detection
- Client memory leak detection
- Bonus server memory leak detection
- Bonus client memory leak detection

### ✅ Stress Tests
- Multiple rapid message transmission
- Very long message stress test
- Performance benchmarking

## 📊 Output Interpretation

- **🟢 [PASS]**: Test completed successfully
- **🔴 [FAIL]**: Test failed - check details above
- **🟡 [WARN]**: Warning or minor issue detected
- **🔵 [INFO]**: Informational message

## 🛠️ Requirements

- `make` and `make bonus` must be run first
- `valgrind` (optional - for memory leak detection)
- All executables must be present in root directory

## 📝 Test Results

The tester provides:
- Individual test results with detailed feedback
- Overall success rate percentage
- Memory leak analysis
- Performance metrics
- Final assessment summary

## 🐛 Troubleshooting

If tests fail:
1. Ensure project compiles without errors: `make && make bonus`
2. Check all executables exist: `ls server client server_bonus client_bonus`
3. Verify no processes are running: `pkill -f "./server"`

## 📈 Success Criteria

- **Excellent**: 90-100% pass rate, no memory leaks
- **Good**: 80-89% pass rate, minor issues
- **Needs Work**: <80% pass rate or major memory leaks

---

**Note**: This tester is designed to be comprehensive and may identify issues not caught during manual testing. Use it to validate your implementation before 42 evaluation.
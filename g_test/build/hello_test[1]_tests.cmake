add_test([=[HelloTest.BasicAssertions]=]  D:/GitHub/ap_college/g_test/build/Debug/hello_test.exe [==[--gtest_filter=HelloTest.BasicAssertions]==] --gtest_also_run_disabled_tests)
set_tests_properties([=[HelloTest.BasicAssertions]=]  PROPERTIES WORKING_DIRECTORY D:/GitHub/ap_college/g_test/build SKIP_REGULAR_EXPRESSION [==[\[  SKIPPED \]]==])
set(  hello_test_TESTS HelloTest.BasicAssertions)

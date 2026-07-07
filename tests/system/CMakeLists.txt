cmake_minimum_required(VERSION 3.20.0)

project(systemTests LANGUAGES C)

list(APPEND TESTS
	common
)

foreach(test ${TESTS})
	add_executable(test_${test}
		${test}.c
		../Unity/src/unity.c
	)

	target_include_directories(test_${test} PRIVATE
        ../../src
        ../Unity/src
    	)

  add_custom_command(
        OUTPUT test_${test}.log
        COMMAND LLVM_PROFILE_FILE=test_${test}.profraw ./test_${test} > test_${test}.log
        COMMAND rm -f test_${test}.testpass test_${test}.testfail
        COMMAND sh -c "[ \"$(tail -1 test_${test}.log)\" = \"OK\" ] && cp test_${test}.log test_${test}.testpass || cp test_${test}.log test_${test}.testfail"
        DEPENDS
            test_${test}
        VERBATIM
    )

  add_custom_target(run-systest-${test} DEPENDS test_${test}.log)

endforeach()


add_custom_target(run-systests
    COMMAND python3 ${CMAKE_CURRENT_LIST_DIR}/../Unity/auto/unity_test_summary.py ${CMAKE_CURRENT_BINARY_DIR}
    DEPENDS
        test_common.log
)

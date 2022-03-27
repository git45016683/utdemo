if [ "$1" == "1" ]; then
#	排除头文件/gtest/usr的信息，收集所有单元测试及源码的覆盖率信息生成覆盖率报告
    lcov -c -d ../build -o all.info --rc lcov_branch_coverage=1\
    &&lcov -r all.info "*.h" -o all.info --rc lcov_branch_coverage=1\
    &&lcov -r all.info "*/gtest/*" -o all.info --rc lcov_branch_coverage=1\
    &&lcov -r all.info "*/usr/*" -o all.info --rc lcov_branch_coverage=1\
    &&genhtml --branch-coverage -o result all.info
else
#	排除头文件/gtest/usr的信息、单元测试的信息，只收集所有源码的覆盖率信息生成覆盖率报告
    lcov -c -d ../build -o all.info --rc lcov_branch_coverage=1\
	&&lcov -r all.info "*/test_src/*" -o all.info --rc lcov_branch_coverage=1\
    &&lcov -r all.info "*.h" -o all.info --rc lcov_branch_coverage=1\
    &&lcov -r all.info "*/gtest/*" -o all.info --rc lcov_branch_coverage=1\
    &&lcov -r all.info "*/usr/*" -o all.info --rc lcov_branch_coverage=1\
    &&genhtml --branch-coverage -o result all.info
fi


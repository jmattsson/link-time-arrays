default: example.d43

SRCS=\
	fanout.cc \
	main.cc \

OBJS=$(SRCS:.cc=.r43)

%.r43: %.cc
	icc430.exe --eec++ -e --diag_suppress=Pa050 --no_wrap_diagnostics --header_context -I../../include -D__MSP430F2618__ --core=430X $< -o $@

# Note: you may need to add a path for dl430xsfn.r43 to be found. It's located
# in <IAR EW430>/430/lib/dlib/
example.d43: $(OBJS)
	xlink.exe $(OBJS) dl430xsfn.r43 -D_STACK_SIZE=400 -f lnk430f2618.xcl -Z'(CONST)seg_listeners' -Fubrof -o $@

.PHONY:clean
clean:
	-rm -f *.?43

ALL = $(basename $(notdir $(shell ls src/*.c)))

all: $(ALL)

ifeq ($(V),1)
    Q=
else
    Q=@
endif

clean:
	$(Q) rm -f $(ALL)

%: src/%.c
	$(Q) gcc -Ofast -Wl,-Ofast -Wall -Wextra -pedantic -std=c11 $< -o $@

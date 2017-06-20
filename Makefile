GUILIBS = -pthread -lfltk -lfltk_images -lX11 -lXext -lXfixes -ldl -lm
CXXFLAGS   = -Wall -Wextra -g -fstack-protector-all -std=c++11
LDFLAGS    =
EXECUTABLE = Schaken
EXTENSION  = cpp
SOURCES    = $(basename $(shell find . -name '*.$(EXTENSION)'))

.PHONY: all
all: $(EXECUTABLE)

Schaken:$(addsuffix .o,$(SOURCES))
	$(CXX) $(LDFLAGS) $^ $(GUILIBS) -o $@

	
%.d: %.$(EXTENSION)
	$(CXX) $(CXXFLAGS) -MM $< -o $@
	echo sed -i 's/:/ $@:/' $@
	printf '\t$$(CC) $$(CXXFLAGS) -c $$< -o $$@\n' >>$@

-include $(addsuffix .d,$(SOURCES))

.PHONY: clean
clean:
	find . -name '*.o' -delete
	find . -name '*.d' -delete
	find . -name '*~'  -delete
	find . -name $(EXECUTABLE) -delete
	

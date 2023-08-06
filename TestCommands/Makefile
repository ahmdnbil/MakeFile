# first makefile

######################################################################
#Like header file in c & cpp
include makeconfig
######################################################################


######################################################################
#setting rule without prerequistes
display:
	@echo "hello world"
	@echo "target is $@"

code:
	@echo "this is target code"
######################################################################



######################################################################
# create variable
var = lab.c
#setting rule with prerequistes
#using '@' to disable echo for each command
all: display code
	@gcc $(var) -o lab.exe
	@echo "first prerequiste $<"
	@echo "all prerequiste $^"
######################################################################


######################################################################
# create text file and put date inside it
# date is a variable from shell
date:
	rm *.txt
	echo "`date` for you" >> log.txt
######################################################################


######################################################################
#declaring function
define Display
	@echo "Entering function"
	@echo "0 is $0"
	@echo "1 is $1"
	@echo "2 is $2"
	@echo "3 is $@"
endef
target1:
	$(call Display,ahmed,$(x))
	@echo
	@echo "target is $@"

# first argument in calling function is function name
# second arg is passing variable
# '$@' will print which target is it come from
######################################################################


######################################################################
#some common function
target2:

#subst
#first arg: text want to be replaced
#second arg: text will be subsituied with 
#third arg: sentence which operation will be done on
	@echo $(subst .c,.cpp, main.c test.c lcd.c)

#patsubst
#first arg: last text want to be replaced [with wildcard]
#second arg: text will be subsituied with 
#third arg: sentence which operation will be done on
	@echo $(patsubst %.c,%.o,x.c.c bar .c)

#sort: sorting sentence
	@echo $(sort zoo bar loss ahmed)

#word: get word by index
	@echo $(word 4,alaa fahmy mhmd abdo)

#wordlsit: get list of words from no to no
	@echo $(wordlist 2, 3,alaa fahmy mhmd abdo)

#firstword: get first word
	@echo $(firstword alaa fahmy mhmd abdo)

#lastword
	@echo $(lastword alaa fahmy mhmd abdo)
######################################################################


######################################################################
#for loop first method [bash script]
loop1:
	@for i in $(LIST);do\
		echo $$i;\
	done
######################################################################


######################################################################
#word like i in classical for loop [counter]
list_2 = $(foreach word,$(List),'\nWord is -$(word)')

loop2:
	@echo $(list_2)
######################################################################


######################################################################
#if condition

#first case: if condition is true, the target existed if not it will be not existed
ifeq '$(file)' 'lab.c'
cond1:
	@echo "true"
endif

#second case the if condition existed inside the rule after target
cond2:
ifeq '$(file)' 'lab.c'
	@echo "true"
endif
######################################################################


######################################################################
#.PHONY
#you can't run the following target becaues it's also file name
#but with ".PHONY: target" it will run correctly	
clean:
	@echo
######################################################################
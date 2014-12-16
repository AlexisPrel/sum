CC = clang 
CFLAGS = -Wall
LIBS = -lm 
GRAPH = gnuplot 
BROWSER = google-chrome
FILE = sol
# DIR=/path	#uncomment #7 and #18 for output to be opened effortlessly 
URL = https://github.com/AlexisPrel/.git

all: sum graph clean

sum: main.c
	${CC} -o $@ $^ $(LIBS)
	./sum > ${FILE}

graph: sum.gpl ${FILE}
	${GRAPH} sum.gpl
#	${BROWSER} ${DIR}/sum.png
    
git-first:
	touch README.md
	git init
	git add .
	git commit -m 'First commit'
	git remote add origin ${URL}
	# Done initialization
	make git-update
	
git-update:
	# Please make sure you have updated README.md
	indent *.c
	git push origin master
	
clean:
	rm -f *.o *~ sum

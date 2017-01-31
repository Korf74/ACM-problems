
all:
	rm -rf TD$(CURRENT).tar.gz
	tar zcvf TD$(CURRENT).tar.gz `find ./TD$(CURRENT)/ | grep '.cpp'`

new:
	mkdir TD$(CURRENT)
	@echo "created directory for TD$(CURRENT)"
clean:
	rm -rf TD$(CURRENT).tar.gz
push:
	git pull
	git add .
	git commit -m "commit for TD$(CURRENT)"
	git push

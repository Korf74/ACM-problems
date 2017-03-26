all:
	rm -rf rcoudert-TD$(CURRENT).tar.gz
	tar zcvf rcoudert-TD$(CURRENT).tar.gz `find rcoudert-TD$(CURRENT)/ | grep '.cpp'`

new:
	mkdir rcoudert-TD$(CURRENT)
	@echo "created directory for TD$(CURRENT)"
clean:
	rm -rf rcoudert-TD$(CURRENT).tar.gz
	find . -type f -name '*.o' -delete
push:
	git pull
	git add .
	git commit -m "commit for TD$(CURRENT)"
	git push

HTMLFLAGS = --book --duplex --no-numbered --format pdf14 --title --size letter --browserwidth 800 

%.pdf: %.html
	-htmldoc $(HTMLFLAGS) --outfile $@ $<

all: dxpDoc.pdf doxygen mappingDocs install

doxygen:
	doxygen

mappingDocs:
	./makeMappingDocs

install:
	cp -f *.html /home/epics/web_software/epics
	cp -f *.png /home/epics/web_software/epics
	cp -f *.jpg /home/epics/web_software/epics
	cp -f *.pdf /home/epics/web_software/epics
	cp -rf dxpDoxygenHTML  /home/epics/web_software/epics/

clean:
	rm -rf dxpDoxygenHTML/*
	rm -f dxpDoc.pdf


realclean: clean

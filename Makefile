.PHONY: all clean
all:
	cd paper && pdflatex -interaction=nonstopmode -halt-on-error paper_en.tex
	cd paper && pdflatex -interaction=nonstopmode -halt-on-error paper_en.tex
	sha256sum paper/paper_en.pdf paper/paper_en.tex > SHA256SUMS
clean:
	rm -f paper/*.aux paper/*.log paper/*.out paper/*.toc

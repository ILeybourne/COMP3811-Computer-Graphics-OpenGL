The intermediate report template contains the following files:

fyp.tex         :	The main file.
config.tex      :	Contains configurations of the report. The student should enter their details at the top of this file.
prelude.tex     :	All material before the start of Chapter 1.
refs.bib        :	The bibliography as a bibtex file.
chapters/*.tex  :	The folder containing each of the chapters as a separate .tex file.
logo_black.png  :	The University of Leeds logo

Feel free to modify any and all files as necessary, as long as you remain within the required
specifications given on Minerva.

In particular:
- "fyp.tex" will need to be modified if you add any new chapters.
- "refs.bib" should be edited to include all references that are cited.

There are various ways to edit LaTeX files:
- Online with Overleaf (free subscription for individual accounts at last time of checking).
- Using a dedicated package such as texmaker, texmanager, texshop etc.
- Use you favourite text editor (many source code editors understand LaTeX syntax).

In the latter case you would normally convert the .tex files to PDF from the command line:
> pdflatex fyp
> bibtex fyp
> pdflatex fyp
> pdflatex fyp
This will produce the file 'fyp.pdf' with references inserted. If you are not using the .bib bibliograpy file,
you can omit the first two lines.

If you do not have 'pdflatex' installed on your system, you can use 'latex' instead, which produces a .dvi file.
This can then be converted to PDF using dvipdf.

If using a school machine and you get errors about a style file not being recognised, try first loading the most recent
version of texlive (i.e. type 'module avail' to see which is the most recent, and then 'module load texlive/20..').

To remove the blank page before a new chapter:
1. Open fyp.tex file
2. Locate the line containing "\documentclass[12pt,a4paper,twoside]{book}"
3. Replace it with the following line "\documentclass[12pt,a4paper,oneside]{book}"
4. Save and re-compile.


Original version Sam Wilson 12th March 2015
Updated Sam Wilson 7th May 2015.
Updated David Head 21st Sept. 2017.
Update David Head 10th Sept. 2018.


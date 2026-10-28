# Performance Evaluation Methods — Notes

LaTeX notes for the labratory of the Performance Evaluation Methods course (University of Pisa), written lesson by lesson. For the theory course notes I used the one provided by prof G. Stea.

The compiled notes are in [`labs/main.pdf`](labs/main.pdf).

## Structure

- `labs/main.tex`: preamble, title page, table of contents and one `\input` per lesson.
- `labs/lessons/lessonNN.tex`: the content of each lesson.
- `labs/exercises/`: code for the lab exercises.
- `labs/main.pdf`: the compiled notes.

The course material (professor's notes) is kept in `docs/` and is not part of the repository.

## Build

```sh
cd labs
latexmk -pdf main.tex
```

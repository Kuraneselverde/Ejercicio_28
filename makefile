all: datos.dat imagenes.png

%.png: %.dat imagenes.png
	python3 graf.py
    
%.dat: a.out
	./a.out
    
a.out: 28.cpp
	g++ 28.cpp

clean:
	rm -rf *.x *.dat *.png

GPP = g++ -O3 -Wall

UTILS = ../../Utilities

WHICH = SET


A = Main.o
C = SetCollection.o
M = MySet.o
O = Operators.o
S = Scanner.o
SL = ScanLine.o
U = Utils.o

Aprog: $A $C $M $O $S $(SL) $U
	$(GPP) -o Aprog $A $C $M $O $S $(SL) $U

Main.o: Main.h Main.cpp
	$(GPP) -c -D$(WHICH) Main.cpp

SetCollection.o: SetCollection.h SetCollection.cpp
	$(GPP) -c -D$(WHICH) SetCollection.cpp

MySet.o: MySet.h MySet.cpp
	$(GPP) -c -D$(WHICH) MySet.cpp

Operators.o: Operators.cpp
	$(GPP) -c -D$(WHICH) Operators.cpp

Scanner.o: $(UTILS)/Scanner.h $(UTILS)/Scanner.cpp
	$(GPP) -c $(UTILS)/Scanner.cpp

ScanLine.o: $(UTILS)/ScanLine.h $(UTILS)/ScanLine.cpp
	$(GPP) -c $(UTILS)/ScanLine.cpp

Utils.o: $(UTILS)/Utils.h $(UTILS)/Utils.cpp
	$(GPP) -c $(UTILS)/Utils.cpp

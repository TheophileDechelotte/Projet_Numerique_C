CPP=g++ -g

RM = rm - f
%.o : %.cpp 
	$(CPP) -o $@ -c $<

Edge.o : Edge.cpp Edge.h
Adjacent_list_representation.o : Adjacent_list_representation.cpp Adjacent_list_representation.h Edge.h Adjacent_matrix_representation.h
Adjacent_matrix_representation.o : Adjacent_matrix_representation.cpp Adjacent_matrix_representation.h Edge.h Adjacent_list_representation.h
main.o : main.cpp Adjacent_list_representation.h Adjacent_matrix_representation.h

graph : main.o Edge.o Adjacent_list_representation.o Adjacent_matrix_representation.o
	$(CPP) $^ -o $@

clean :
	$(RM) main.o Edge.o Adjacent_list_representation.o Adjacent_matrix_representation.o graph

.PHONY : clean


%2 segundo punto

materias_estudiante(juan,matematicas,quimica,ingles,sociales,ciencias,fisica).
materias_estudiante(david,matematicas,quimica,ingles,sociales,ciencias,fisica).
materias_estudiante(alejandra,matematicas,quimica,ingles,sociales,ciencias,fisica).
materias_estudiante(karen,,matematicas,quimica,ingles,sociales,ciencias,fisica).
materias_estudiante(natalia,matematicas,quimica,ingles,sociales,ciencias,fisica).
materias_estudiante(oscar,matematicas,quimica,ingles,sociales,ciencias,fisica).
materias_estudiante(julian,matematicas,quimica,ingles,sociales,ciencias,fisica).
materias_estudiante(laura,matematicas,quimica,ingles,sociales,ciencias,fisica).
materias_estudiante(diana,matematicas,quimica,ingles,sociales,ciencias,fisica).
materias_estudiante(enrique,matematicas,quimica,ingles,sociales,ciencias,fisica).

notas_estudiante(juan,50,42,50,24,13,45).
notas_estudiante(david,50,20,10,35,37,40).
notas_estudiante(alejandra,10,25,35,43,50,29).
notas_estudiante(karen,35,40,50,30,20,20).
notas_estudiante(natalia,35,46,23,43,50,10).
notas_estudiante(oscar,20,10,40,50,30,45).
notas_estudiante(julian,50,50,45,30,50,0).
notas_estudiante(laura,33,24,50,34,50,10).
notas_estudiante(diana,12,14,20,30,50,40).
notas_estudiante(enrique,50,45,48,40,45,35).

matematicas_r(X,A):- notas_estudiante(X,A,B,C,D,E,F), A<30, write( 'reprobo').
matematicas_a(X,A):- notas_estudiante(X,A,B,C,D,E,F), A>=30, write( 'aprobo').
quimica_r(X,B):- notas_estudiante(X,A,B,C,D,E,F), B<30, write( 'reprobo').
quimica_a(X,B):- notas_estudiante(X,A,B,C,D,E,F), B>=30, write( 'aprobo').
ingles_r(X,C):- notas_estudiante(X,A,B,C,D,E,F), C<30, write( 'reprobo').
ingles_a(X,C):- notas_estudiante(X,A,B,C,D,E,F), C>=30, write( 'aprobo').
sociales_r(X,D):- notas_estudiante(X,A,B,C,D,E,F), D<30, write( 'reprobo').
sociales_a(X,D):- notas_estudiante(X,A,B,C,D,E,F), D>=30, write( 'aprobo').
ciencias_r(X,E):- notas_estudiante(X,A,B,C,D,E,F), E<30, write( 'reprobo').
ciencias_a(X,E):- notas_estudiante(X,A,B,C,D,E,F), E>=30, write( 'aprobo').
fisica_r(X,F):- notas_estudiante(X,A,B,C,D,E,F), F<30, write( 'reprobo').
fisica_a(X,F):- notas_estudiante(X,A,B,C,D,E,F), F>=30, write( 'aprobo').
%-----------------------------------------------------


%3 Tercer punto

divisible_por_2(X):- 0 is X mod 2, write(X) ,write( ' es divisible por 2'); 1 is X mod 2, write(X), write( ' no es divisible por 2').
divisible_por_3(X):- 0 is X mod 3, write(X) ,write( ' es divisible por 3'); 1 is X mod 3, write(X), write( ' no es divisible por 3').
divisible_por_5(X):- 0 is X mod 5, write(X) ,write( ' es divisible por 5'); 1 is X mod 5, write(X), write( ' no es divisible por 5').
verificar_div(X):- 0 is X mod 2,write(X), write( 'es divisible por 2');0 is X mod 3, write(X) ,write( ' es divisible por 3');0 is X mod 5, write(X), write( ' es divisible por 5');1 is X mod 2,write(X), write( 'no es divisible por 2');1 is X mod 3, write(X) ,write( ' no es divisible por 3');1 is X mod 5, write(X), write( ' no es divisible por 5').

%------------------------------------------------------



nombre_deporte(juan,atlestismo,natacion).
nombre_deporte(david,gimnasia,futbol).
nombre_deporte(alejandra,voleibol,natacion).
nombre_deporte(karen,gimnasia,voleibol).
nombre_deporte(oscar,atlestismo,gimnasia).
nombre_deporte(laura,futbol,voleibol).
nombre_deporte(patricia,atlestismo,natacion).
nombre_deporte(diana,atlestismo,gimnasia).
nombre_deporte(enrique,voleibol,natacion).
nombre_deporte(valentina,gimnasia,atlestismo).

practicas_semana(gimnasia,martes,jueves).
practicas_semana(voleibol,lunes,viernes).
practicas_semana(natacion,sabados,domingos).
practicas_semana(futbol,miercoles,viernes).
practicas_semana(,sabados,jueves).

deporte(gimnasia,4horas)
deporte(voleibol,4horas)
deporte(natacion,4horas)
deporte(futbol,4horas)
deporte(atletismo,4horas)


horas_deporte(A,B):- deporte(A,B).

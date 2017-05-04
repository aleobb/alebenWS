function Mostrar()
{
	//Genero el número RANDOM entre 1 y 10 
	var number = Math.floor(Math.random()*10)+1;
	// la suguiente cadena también funciona porque parseInt trunca un numero a quedándose con su entero sin redondear:
	// var number = parseInt(Math.random()*10)+1;
	alert(number);

}//FIN DE LA FUNCIÓN
function Mostrar()
{
	//Genero el número RANDOM entre 1 y 10 
var number = Math.floor(Math.random()*10)+1;
alert("NOTA: " + number);
if(number<4)	
	{
		alert("Vamos, la proxima se puede");
	}
else if(number<9)
	{
		alert("APROBÓ");
	}
else
	{
		alert("EXELENTE");
	}
}//FIN DE LA FUNCIÓN
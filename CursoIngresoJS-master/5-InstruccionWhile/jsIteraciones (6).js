function Mostrar()
{

	var contador=1;
	var acumulador=0;

//var num = parseInt(prompt("Ingrese el " + contador + "º numero."))
//alert(isNaN(num))


while (contador<6)
{
	var num = parseInt(prompt("Ingrese el " + contador + "º numero."));
	while (isNaN(num))
		{
			num = parseInt(prompt("El dato ingresado es inválido. Ingrese el " + contador + "º numero nuevamente."));
		}
	acumulador = num + acumulador;
	contador++;
}


document.getElementById("suma").value=acumulador;
document.getElementById("promedio").value=acumulador/5;

}//FIN DE LA FUNCIÓN
function Mostrar()
{

	var contador=1;
	var acumulador=0;
	var respuesta;

do 
{
	var num = parseInt(prompt("Ingrese el " + contador + "º numero."));
	while (isNaN(num))
		{
			num = parseInt(prompt("El dato ingresado es inválido. Ingrese el " + contador + "º numero nuevamente."));
		}
	acumulador = num + acumulador;
	contador++;
	respuesta = confirm("Desea continuar ingresando valores?");
}while(respuesta);



document.getElementById("suma").value=acumulador;
document.getElementById("promedio").value=acumulador/(contador-1);

}//FIN DE LA FUNCIÓN
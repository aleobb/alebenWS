
function Mostrar()
{
	var contador = 1;
	var num;

do 
{
	num = parseInt(prompt("Ingrese el " + contador + "º numero."));
	while (isNaN(num))
		{
			num = parseInt(prompt("El dato ingresado es inválido. Ingrese el " + contador + "º numero nuevamente."));
		}
	if(contador == 1)
	{
		min = num;
		max = num;
	}
	else if ( num > max )
	{
		max = num;
	}
	else if ( num < min )
	{
		min = num;
	}
	
	/* Antes hacía:
	if(contador==1)
	{
		var max = num;
		var min = num;
	}
	max = Math.max(num, max);
	min = Math.min(num, min);
	*/
	
	contador++;
	var seguir = confirm("Desea continuar ingresando valores?");
}while(seguir);


document.getElementById("maximo").value=max;
document.getElementById("minimo").value=min;




}//FIN DE LA FUNCIÓN
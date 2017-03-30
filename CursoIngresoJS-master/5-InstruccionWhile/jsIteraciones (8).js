function Mostrar()
{

	var contador = 1;
	var positivo = 0;
	var negativo = 1;

do 
{
	var num = parseInt(prompt("Ingrese el " + contador + "º numero."));
	while (isNaN(num) || num==0)
		{
			num = parseInt(prompt("El dato ingresado es inválido. Ingrese el " + contador + "º numero nuevamente."));
		}
	contador++;
	if(num>0)
	{
		positivo = num + positivo;
	} 
	else
	{
		negativo = num * negativo;
	}
	var respuesta = confirm("Desea continuar ingresando valores?");
}while(respuesta);


document.getElementById("suma").value=positivo;
document.getElementById("producto").value=negativo;

}//FIN DE LA FUNCIÓN
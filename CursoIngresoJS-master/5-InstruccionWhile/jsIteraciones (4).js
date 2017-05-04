function Mostrar()
{

	var numero = parseInt(prompt("ingrese un número entre 0 y 9."));

while ( numero < 0 || numero > 9 || isNaN(numero) )
{
	numero = parseInt(prompt("El valor ingresado no es un numero del 0 al 9. Reingrese el valor"));
}
document.getElementById("Numero").value = numero;

}//FIN DE LA FUNCIÓN
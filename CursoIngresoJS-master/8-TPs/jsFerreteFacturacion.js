/*1.	Para el departamento de facturación:
A.	Ingresar tres precios de productos y mostrar la suma de los mismos.
B.	Ingresar tres precios de productos y mostrar el promedio de los mismos.
C.	ingresar tres precios de productos  y mostrar precio final (más IVA 21%).
*/
function Sumar () 
{
	var suma = parseInt(document.getElementById("PrecioUno").value) + parseInt(document.getElementById("PrecioDos").value) + parseInt(document.getElementById("PrecioTres").value);
    alert("La suma de los precios es: "+ suma);
}
function Promedio () 
{
	var Promedio = (parseInt(document.getElementById("PrecioUno").value) + parseInt(document.getElementById("PrecioDos").value) + parseInt(document.getElementById("PrecioTres").value))/3;

	alert("El Promedio es: "+ Promedio);	
}
function PrecioFinal () 
{

	var PrecioUno=document.getElementById("PrecioUno").value;
	var PrecioDos=document.getElementById("PrecioDos").value;
	var PrecioTres=document.getElementById("PrecioTres").value;

	PrecioUno=parseInt(PrecioUno)*1.21;
	PrecioDos=parseInt(PrecioDos)*1.21;
	PrecioTres=parseInt(PrecioTres)*1.21;

	alert("El precio 1 final es: " + PrecioUno + " El precio 2 final es: " + PrecioDos + " El precio 3 final es: " + PrecioTres);
}
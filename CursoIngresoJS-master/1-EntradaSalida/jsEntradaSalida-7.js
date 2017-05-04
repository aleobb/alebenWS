/*Debemos lograr tomar Los numeros por ID ,
transformarlos a enteros (parseInt),realizar la operación correcta y 
mostar el resulto por medio de "ALERT"
ej.: "la Resta es 750"*/ 
function sumar()
{	
	var one;
    var two;
    var operacion;
    one = document.getElementById("numeroUno").value;
    two = document.getElementById("numeroDos").value;
    one = parseInt(one);
    two = parseInt(two);
    operacion = one + two
    alert ("la suma es " + operacion)

}

function restar()
{
	var one;
    var two;
    var operacion;
    one = document.getElementById("numeroUno").value;
    two = document.getElementById("numeroDos").value;
    one = parseInt(one);
    two = parseInt(two);
    operacion = one - two
    alert ("la resta es " + operacion)
}

function multiplicar()
{ 
	var one;
    var two;
    var operacion;
    one = document.getElementById("numeroUno").value;
    two = document.getElementById("numeroDos").value;
    one = parseInt(one);
    two = parseInt(two);
    operacion = one * two
    alert ("el producto es " + operacion)

}

function dividir()
{
	var one;
    var two;
    var operacion;
    one = document.getElementById("numeroUno").value;
    two = document.getElementById("numeroDos").value;
    one = parseInt(one);
    two = parseInt(two);
    operacion = one / two
    alert ("la division es " + operacion)
}


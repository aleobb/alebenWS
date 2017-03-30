/*Debemos lograr tomar Los numeros por ID ,
transformarlos a enteros (parseInt) y Sumarlos.
Mostar el resulto por medio de "ALERT"*/
function sumar()
{
    var one;
    var two;
    var suma;
    one = document.getElementById("numeroUno").value;
    two = document.getElementById("numeroDos").value;
    one = parseInt(one);
    two = parseInt(two);
    suma = one + two;
alert ("la suma es " + suma);

}


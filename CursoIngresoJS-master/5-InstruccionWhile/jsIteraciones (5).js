function Mostrar()
{

var sexo = prompt("ingrese f ó m .");
sexo = sexo.toLowerCase()
while(sexo != "f" && sexo != "m")
 {
     sexo = prompt("El dato ingresado es invalido. Ingrese f ó m.");
 }

document.getElementById('Sexo').value=sexo;

}//FIN DE LA FUNCIÓN
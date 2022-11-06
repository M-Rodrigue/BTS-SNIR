let r = prompt("Entrer la racine carré à calculer :");
let it = prompt("Entrer le nombre d'itérations :");
let xn = ;

document.getElementById("r").innerHTML = r;
document.getElementById("it").innerHTML = it;

function maracine(r, it) {
  for (let i = 0; i < it; i++) {
    xn = (1 / 2) * (xn + r / xn);
  }
}
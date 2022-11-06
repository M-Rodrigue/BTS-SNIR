// Nous utilisons la méthode du floor() car celle-ci permet de donner un interval plus grand que 0 et 1

/* Image1 */
let randomNumber1 = Math.floor(Math.random() * 6) + 1;
let randomImageSource1 = `images\/dice${randomNumber1}.png`;
let image1 = document.querySelectorAll("img")[0].setAttribute("src", randomImageSource1);

/* Image2 */
let randomNumber2 = Math.floor(Math.random() * 6) + 1;
let randomImageSource2 = `images\/dice${randomNumber2}.png`;
let image2 = document.querySelectorAll("img")[1].setAttribute("src", randomImageSource2);

/* H1 */
if (randomNumber1 > randomNumber2) {
  document.querySelector("h1").innerHTML = "&#128681; Player 1 Wins !";
} else if (randomNumber2 > randomNumber1) {
  document.querySelector("h1").innerHTML = "Player 2 Wins ! &#128681;";
} else {
  document.querySelector("h1").innerHTML = "Draw !";
}
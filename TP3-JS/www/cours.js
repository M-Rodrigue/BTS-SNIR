/* Exercice 1 */
// Avant permutation
//let a = prompt("Modifier A");
//let b = prompt("Modifier B");
//alert(`Avant permutation :\na=${a} et b=${b}`);

// Après permutation
//let c = a;
//a = b;
//b = c;
//alert(`Après permutation :\na=${a} et b=${b} puis c=${c}`);

/* Exercice 2 */
//let tweet = prompt("Composer votre tweet :");
//let tweetCount = tweet.length;
//alert(`Vous avez écris ${tweetCount} caractères, il vous reste ${140 - tweetCount} caractères`);

/* Exercice 3 */
//let tweet = prompt("Composer votre tweet :");
//let tweetCount = tweet.length;
//let tweetUnder140 = tweet.slice(0, 10);
//alert(`Vous avez écris ${tweetCount} caractères, il vous reste ${10 - tweetCount} caractères`);
//alert(`${tweetUnder140}`);

/* Exercice 4 */
//let firstName = prompt("Ecrire votre prénom :");
//let firstChar = firstName.slice(0, 1).toUpperCase(); (Non opti: firstChar = firstChar.toUpperCase();)
//firstName = firstName.toLowerCase();
//firstName = firstChar + firstName.slice(1, firstName.lenght);
//alert(`Bonjour, ${firstName}`);

/* Exercice 5 */
//let dogAge = prompt("Quel est l'âge de votre chien :");
//let humanAge = (dogAge - 2) * 4 + 24;
//alert(`Votre chien est agé de ${humanAge} ans en années homme.`);

/* Exercice 6 */
let age = prompt("Quel est votre âge ?");

function lifeInWeeks(age) {
  let yearsRemaining = 90;
  yearsRemaining = yearsRemaining - age;
  let days = 365 * yearsRemaining;
  let weeks = 52 * yearsRemaining;
  let months = 12 * yearsRemaining;
}


alert(`Avec ${age} ans c'est ${days} jours, ${weeks} semaines et ${months} mois qu'il reste avant vos 90 ans.`);

document.getElementById("p1").innerHTML = lifeInWeeks(age);

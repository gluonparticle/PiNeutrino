const prompt = require('prompt-sync')();
let input = prompt("Enter 5 cities separated by commas: ");
let cities = input.split(',').map(city => city.trim());

console.log("Initial cities:", cities);
console.log("Total number of cities:", cities.length);

let newCity = prompt("Enter a city to add to the end: ");
cities.push(newCity);

console.log("Cities after adding a new one:", cities);

console.log("Removing the first city:", cities[0]);
cities.shift();

console.log("Cities after removing the first one:", cities);

let searchCity = prompt("Enter a city to find its index: ");
let cityIndex = cities.indexOf(searchCity);

console.log("Index of " + searchCity + ":", cityIndex !== -1 ? cityIndex : "City not found");

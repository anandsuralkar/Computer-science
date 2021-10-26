var nums=[1,2,3,4,5];
let string="My name is anand";
// console.log(string.slice(2,7));
//console.log(string.replace("anand","rohan"));
// let mydate=new Date();
// console.log(mydate.getTime());
// console.log(mydate.getFullYear());
// console.log(mydate.getHours());
// console.log(mydate.getMinutes());
// console.log(mydate.getDay());
// let elem =  document.getElementById('click');
// console.log(elem);

let elemClass = document.getElementsByClassName('container');
// console.log(elemClass[0]);

elemClass[0].classList.add("bg-primary");

tn=document.getElementsByTagName('div');
console.log(tn)
createdElement=document.createElement('p');
createdElement.innerText="this is created para";

tn[0].appendChild(createdElement);
createdElement2 = document.createElement('b');
createdElement2.innerText = "this is created bold";
tn[0].replaceChild(createdElement2,createdElement);
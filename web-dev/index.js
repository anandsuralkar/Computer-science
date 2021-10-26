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
// console.log(tn)
createdElement=document.createElement('p');
createdElement.innerText="this is created para";

tn[0].appendChild(createdElement);
createdElement2 = document.createElement('b');
createdElement2.innerText = "this is created bold";
tn[0].replaceChild(createdElement2,createdElement);

//Selecting using Query
sel = document.querySelector('.container');
// console.log(sel);
sel = document.querySelectorAll('.container');
console.log(sel);

// Events in JavaScript
/*
function clicked(){
    console.log("clicked");
}
window.onload=function(){
    console.log("document was loaded");
}
firstContainer.addEventListener('click',function(){
    console.log("click hua");
})
firstContainer.addEventListener('mouseover',function(){
    console.log("mouse on container");
})
firstContainer.addEventListener('mouseout',function(){
    console.log("mouse out of container");
})
firstContainer.addEventListener('mouseup',function(){
    console.log("mouse up when clicked on container");
})
firstContainer.addEventListener('mousedown',function(){
    console.log("mouse down when clicked on container");
})
*/

firstContainer.addEventListener('click',function(){
    document.querySelectorAll('.container')[1].innerHTML = "<b>We have Clicked</b>";
    console.log("clicked on container");
})

var input1;
var input2;
var inputToWin;
var inputDepth;
var gameWidth = 4;
var gameHeight = 4;
var toWin = 3;
var rect1;
var player = 1;
var start = 0;
var move =0;
var depthMax =4;


function setup() {//Wbudowana
  createCanvas(400, 400);

  input1 = createInput();
  input2 = createInput();
  inputToWin = createInput();
  inputDepth = createInput();

  input1.changed(dr);
  input2.changed(dr);
  inputToWin.changed(function(){toWin = inputToWin.value()-1});
  inputDepth.changed(function(){depthMax = inputDepth.value();
    console.log(depthMax + " " + "--------------")
  });
  dr();
}


function dr() {
// console.log(Number.isInteger(parseInt(input1.value(), 10)))
  if(Number.isInteger(parseInt(input1.value(), 10))){
    gameWidth = parseInt(input1.value(), 10)
    // depthMax = gameWidth*gameHeight;
  }
  if(Number.isInteger(parseInt(input2.value(), 10))){
    gameHeight = parseInt(input2.value(), 10)
    // depthMax = gameWidth*gameHeight;
  }
  // console.log(Number.isInteger(gameWidth))

  rect1 = [];
  for (var i = 0; i < gameWidth; i++) {
    rect1[i] = [];
  }
  // console.log(rect1);

  for (var i = 0; i < gameWidth; i++)
    for (var j = 0; j < gameHeight; j++)
      rect1[i][j] = 0;
  console.log(gameWidth + " " + gameHeight)

  // player = 1;
  if(move == gameWidth*gameHeight)
    if(player == 2)
      player =1;
    else
      player =2;
  move =0;
  start = 0;
  if(player ==2){
    start =1 ;
    chooseMove();}
  // if()
  // rect1[0][0] = 2;
  // rect1[2][0] = 2;
  // rect1[0][1] = 1;
  // rect1[1][1] = 1;
  // rect1[2][1] = 2;
  // move = 5;
  // player = 1;

}

function whereMouseIs() {
  push(); // Start another new drawing state
  fill(204, 153, 123);
  stroke(0, 102, 153);
  rect(mouseX - mouseX % (width / gameWidth), mouseY - mouseY % (height / gameHeight), width / gameWidth, height / gameHeight);
  pop();

}

function changePlayer(){
  if(player == 1)
    player = 2;
  else if(player == 2)
    player = 1;
}

function mousePressed() {//Wbudowana funckja
  // console.log(parseInt(gameWidth*(mouseX/gameWidth), 10));
  // console.log(1);
  let w = parseInt(gameWidth * (mouseX / width), 10);
  let h = parseInt(gameHeight * (mouseY / height), 10);
  if(rect1[w][h] == 0){
    let tMove = {x:w, y:h};
    // moveAI(tMove)
    if(!moveAI(tMove))
      chooseMove();
  }

  // console.log(rect1[parseInt(gameWidth * (mouseX / gameWidth), 10)][parseInt(gameHeight * (mouseY / height), 10)]);

  // console.log(rect1);
}

function drawClicked() {
  for (var i = 0; i < gameWidth; i++)
    for (var j = 0; j < gameHeight; j++){
      if (rect1[i][j] == 1) {
        push(); // Start another new drawing state
        fill(204, 255, 123);
        stroke(0, 102, 153);
        rect(i * (width / gameWidth), j * (height / gameHeight), width / gameWidth, height / gameHeight);
        pop();
      }
      else if (rect1[i][j] == 2) {
        push(); // Start another new drawing state
        fill(204, 123, 255);
        stroke(0, 102, 153);
        rect(i * (width / gameWidth), j * (height / gameHeight), width / gameWidth, height / gameHeight);
        pop();
      }
    }
}

function drawGrid(){
  for (var i = 0; i < gameWidth; i++) {
    // console.log(gameWidth);
    line(width * i / gameWidth, 0, width * i / gameWidth, height);
  }
  for (var i = 0; i < gameHeight; i++) {
    // console.log(gameHeight);
    line(width, height * i / gameHeight, 0, height * i / gameHeight);
  }
}


function isWin(){
  // for(let i=0; i<gameHeight; i++){
  //   for(let j=0; j<gameHeight; j++){
  //     console.log(rect1[i][j]);}
  //     console.log("\n");
  //   }
  //Poziom -----------------------------------------
  let t=0;
  let t1 = 0;
  let t1Type = 0;
  for(let i=0; i<gameHeight; i++){
    t = 0;
    t1 = 0;
    while(t<gameWidth){
      if(rect1[t][i]==t1Type && rect1[t][i]!=0)
        t1++;
      else{
        t1=1;
        t1Type = rect1[t][i];
      }
      t++;
      if(t1 > toWin){
        // console.log("WIN" + t + " " + t1 + " " + i);
        return t1Type;
      }
    }
  }
  //Pion -----------------------------------------
  t=0;
  t1 = 0;
  t1Type = 0;
  for(let i=0; i<gameWidth; i++){
    t = 0;
    t1 = 0;
    while(t<gameHeight){
      if(rect1[i][t]==t1Type && rect1[i][t]!=0)
        t1++;
      else{
        t1=1;
        t1Type = rect1[i][t];
      }
      t++;
      if(t1 > toWin){
        // console.log("WIN" + t + " " + t1 + " " + i);
        return t1Type;
      }
    }
  }
  //Skos_prawo duł -----------------------------------------
  t=0;
  t1 = 0;
  t1Type = 0;
  for(let i=0; i<gameHeight; i++){
    t = 0;
    t1 = 0;
    while(t+i<gameHeight){
      if(rect1[t][i+t]==t1Type && rect1[t][i+t]!=0)
        t1++;
      else{
        t1=1;
        t1Type = rect1[t][i+t];
      }
      t++;
      if(t1 > toWin){
        // console.log("WIN" + t + " " + t1 + " " + i);
        return t1Type;
      }
    }
  }
  t=0;
  t1 = 0;
  t1Type = 0;
  for(let i=1; i<gameWidth; i++){
    t = 0;
    t1 = 0;
    while(t+i<gameWidth){
      if(rect1[i+t][t]==t1Type && rect1[i+t][t]!=0)
        t1++;
      else{
        t1=1;
        t1Type = rect1[i+t][t];
      }
      t++;
      if(t1 > toWin){
        // console.log("WIN" + t + " " + t1 + " " + i);
        return t1Type;
      }
    }
  }
  //Sko_Góra Praw -----------------------------------------
  t=0;
  t1 = 0;
  t1Type = 0;
  for(let i=0; i<gameHeight; i++){
    t = 0;
    t1 = 0;
    while(t+i>=0){
      if(rect1[-t][i+t]==t1Type && rect1[-t][i+t]!=0)
        t1++;
      else{
        t1=1;
        t1Type = rect1[-t][i+t];
      }
      t--;
      if(t1 > toWin){
        // console.log("WIN" + t + " " + t1 + " " + i);
        return t1Type;
      }
    }
  }
  t=0;
  t1 = 0;
  t1Type = 0;
  for(let i=1; i<gameWidth; i++){
    t = 0;
    t1 = 0;
    while(-t+i<gameWidth){
      if(rect1[i-t][gameHeight-1+t]==t1Type && rect1[i-t][gameHeight-1+t]!=0)
        t1++;
      else{
        t1=1;
        t1Type = rect1[i-t][gameHeight-1+t];
      }
      t--;
      if(t1 > toWin){
        // console.log("WIN" + t + " " + t1 + " " + i);
        return t1Type;
      }
    }
  }

  return 0;
}



function minmax(depth, alfa, beta){


  let localIsWin = isWin();
  if(localIsWin == 2){
      // console.log(gameWidth*gameHeight-depth);
      return (gameWidth*gameHeight-depth);}
  if(localIsWin == 1){
      console.log(-gameWidth*gameHeight+depth);
      return -gameWidth*gameHeight+depth;}
  // console.log(localIsWin);
  // console.log(depth + " "+ depthMax);
  console.log(depth +" "+ move);// + "  " + best);

  if(move+depth == gameWidth*gameHeight-1){
    // console.log(depth);
    return 0;
  }

  let  best = -gameWidth*gameHeight*2;
  let bestTemp;
  if((move+depth)%2 == 0){

    if(depth > depthMax){
      console.log("wwwwwwwwwww")
      return 0;}
    for(let i=0; i<gameWidth; i++){
      for(let j=0; j<gameHeight; j++){
        if(rect1[i][j]==0){
          // if((move+depth)%2 ==0)
          //   rect1[i][j] = 1;
          // else
          rect1[i][j] = 2;
          // console.log(i + " " + j);
          bestTemp = minmax(depth+1, alfa, beta);
          rect1[i][j] = 0;
          if(bestTemp > best)
            best = bestTemp;
          if(best > alfa)
            alfa = best;
          if(beta <= alfa)
            break;
        }
      }
    }
  }
  else{
    best = -best;
    if(depth > depthMax){
      console.log("Ssssssssss")
      return 0;

    }
    for(let i=0; i<gameWidth; i++){
        for(let j=0; j<gameHeight; j++){
          if(rect1[i][j]==0){
            // if((move+depth)%2 ==0)
            //   rect1[i][j] = 1;
            // else
            rect1[i][j] = 1;
            bestTemp = minmax(depth+1, alfa, beta);
            rect1[i][j] = 0;
          // console.log(i + " " + j);
            if(bestTemp < best)
              best = bestTemp;
            if(best < beta)
              beta = best;
            if(beta <= alfa)
              break;
          }
        }
      }
    }
  console.log(best + " " + depth);
  return best;

}

function moveAI(move1){
  rect1[move1.x][move1.y]=player;
  move++;
  changePlayer();
  if(isWin() || move == gameWidth*gameHeight){
  // console.log("LEL");
    // console.log(move1.x + " " + move1.y);
    // console.log(isWin());
    dr();
    return 1;
  }
  return 0;
}

function chooseMove(){
  // debug();
  let whatMove = {x: -1, y:-1};
  let bestTemp = -gameWidth*gameHeight;
  best = -gameWidth*gameHeight-5;
  console.log(" " + whatMove.x + " "+ whatMove.y + " " + best);
  for(let i=0; i<gameWidth; i++){
      for(let j=0; j<gameHeight; j++){
        if(rect1[i][j]==0){
          rect1[i][j]=2;
          // console.log(i + " " + j);
          // if(i==2 && j ==0)
            // bestTemp =debug(minmax(1));
          bestTemp = minmax(start, best, -best);
          console.log(i + " " + j + " " + bestTemp + " " + best);
          rect1[i][j]=0;
          if(bestTemp == -20)
            bestTemp = 0;
          if(bestTemp > best){
            // console.log(i + " " + j);// + " " + bestTemp);
            console.log("aa------" + bestTemp);
            best = bestTemp;
            whatMove.x = i;
            whatMove.y = j;
          }
        }
      }
    }
    console.log(" " + whatMove.x + " "+ whatMove.y + " " + best);
    moveAI(whatMove);
}


function draw() {//Wbudowana
  background(220);
  drawGrid();
  drawClicked();
  whereMouseIs();
  // is
}
// var input1 = 13;
// var input2 = 13;
// var gameWidth = 13;
// var gameHeight = 13;
// var rect1;
//
// function setup() {//Wbudowana
//   createCanvas(400, 400);
//   var rect1 = new Array(input1);
//
//   for (var i = 0; i < rect1.length; i++) {
//     rect1[i] = new Array(input2);
//   }
//   input1 = createInput();
//   input2 = createInput();
//
//   input1.changed(dr);
//   input2.changed(dr);
// }
//
//
// function dr() {
//   rect1 = [];
//
//   for (var i = 0; i < input1.value(); i++) {
//     rect1[i] = [];
//   }
//   // console.log(rect1);
//
//   for (var i = 0; i < input1.value(); i++)
//     for (var j = 0; j < input2.value(); j++)
//       rect1[i][j] = 0;
//
//   createCanvas(400, 400);
//
// }
//
// function whereMouseIs() {
//   push(); // Start another new drawing state
//   fill(204, 153, 123);
//   stroke(0, 102, 153);
//   rect(mouseX - mouseX % (gameWidth / input1.value()), mouseY - mouseY % (height / input2.value()), gameWidth / input1.value(), height / input2.value());
//   pop();
//
// }
//
// function mousePressed() {//Wbudowana funckja
//   // console.log(parseInt(input1.value()*(mouseX/gameWidth), 10));
//   // console.log(1);
//   rect1[parseInt(input1.value() * (mouseX / gameWidth), 10)][parseInt(input2.value() * (mouseY / height), 10)] = 1;
//   // console.log(rect1[parseInt(input1.value() * (mouseX / gameWidth), 10)][parseInt(input2.value() * (mouseY / height), 10)]);
//
//   console.log(rect1);
// }
//
// function drawClicked() {
//   push(); // Start another new drawing state
//   fill(204, 255, 123);
//   stroke(0, 102, 153);
//   for (var i = 0; i < input1.value(); i++)
//     for (var j = 0; j < input2.value(); j++)
//       if (rect1[i][j] == 1) {
//         rect(i * (gameWidth / input1.value()), j * (height / input2.value()), gameWidth / input1.value(), height / input2.value());
//       }
//   pop();
// }
//
// function drawGrid(){
//   for (var i = 0; i < input1.value(); i++) {
//     // console.log(input1.value());
//     line(gameWidth * i / input1.value(), 0, gameWidth * i / input1.value(), height);
//   }
//   for (var i = 0; i < input2.value(); i++) {
//     // console.log(input2.value());
//     line(gameWidth, height * i / input2.value(), 0, height * i / input2.value());
//   }
// }
//
// function draw() {//Wbudowana
//   background(220);
//   drawGrid();
//   drawClicked();
//   whereMouseIs();
// }





// function isWin(){
//   // for(let i=0; i<gameHeight; i++){
//   //   for(let j=0; j<gameHeight; j++){
//   //     console.log(rect1[i][j]);}
//   //     console.log("\n");
//   //   }
//   let t=0;
//   console.log("A")
//   for(let i=0; i<gameHeight; i++)//poziomP
//   {
//     console.log(t + " " + toWin)
//     while(t+toWin<gameWidth){
//       console.log("C")
//       if(rect1[t][i]==rect1[t+toWin][i]){
//         let t1 = t;
//         while(t1<t+toWin){
//           console.log("D")
//           if(rect1[t][i]!=rect1[t1][i])
//             break;
//           else
//             t1++;
//           }
//         if(t1 == t+toWin){
//           console.log("WIN")
//           break;
//         }
//       }
//       else
//         t += toWin;
//     }
//   }
//
//
// }

// let t=0;
// let t1 = 0;
// for(let i=0; i<gameHeight; i++){//Poziom
//   t = 0;
//   while(t+toWin<gameWidth){
//     if(rect1[t][i]==rect1[t+toWin][i] && rect1[t][i]!=0){
//       t1 = t;
//       while(t1<t+toWin){
//         if(rect1[t][i]!=rect1[t1][i])
//           break;
//         else
//           t1++;
//         }
//       if(t1 == t+toWin){
//         console.log("WIN" + t + " " + t1 + " " + i);
//         break;
//       }
//     }
//     t += toWin;
//   }
// }
// t=0;
// t1 = 0;
// for(let i=0; i<gameWidth; i++){//Poziom
//   t = 0;
//   // console.log("C"+ t + " " + t1 + " " + i);
//   while(t+toWin<gameHeight){
//     // console.log("D"+ t + " " + t1 + " " + i);
//     // console.log("D"+ t + " " + rect1[i][t] + " " + rect1[i][t+toWin]);
//     if(rect1[i][t]==rect1[i][t+toWin] && rect1[i][t]!=0){
//       // console.log("E");
//       t1 = t;
//       while(t1<t+toWin){
//         if(rect1[i][t]!=rect1[i][t1])
//           break;
//         else
//           t1++;
//         }
//       if(t1 == t+toWin){
//         console.log("WIN" + t + " " + t1 + " " );
//         break;
//       }
//     }
//     t += toWin;
//   }
// }
//
// t=0;
// t1 = 0;
// for(let i=0; i<gameWidth-toWin; i++){//Poziom
//   t = 0;
//   // console.log("C"+ t + " " + t1 + " " + i);
//   while(t+toWin<gameHeight){
//     // console.log("D"+ t + " " + t1 + " " + i);
//     // console.log("D"+ t + " " + rect1[i][t] + " " + rect1[i][t+toWin]);
//     if(rect1[i][t]==rect1[i][t+toWin] && rect1[i][t]!=0){
//       // console.log("E");
//       t1 = t;
//       while(t1<t+toWin){
//         if(rect1[i][t]!=rect1[i][t1])
//           break;
//         else
//           t1++;
//         }
//       if(t1 == t+toWin){
//         console.log("WIN" + t + " " + t1 + " " );
//         break;
//       }
//     }
//     t += toWin;
//   }
// }

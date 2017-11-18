const counter = require('./counter')
const fs = require('fs');
const async = require('async');
const path = require('path');


var convert=(inFile,outFile,direct,addChar,addNum)=>{
direct=direct.split('2');
decode={
  RU: ['Й','Ц','У','К','Е','Н','Г','Ш','Щ','З','Х','Ъ','Ф','Ы','В','А','П','Р','О','Л','Д','Ж','Э' ,'/','|','Я','Ч','С','М','И','Т','Ь','Б','Ю',',' ,'й','ц','у','к','е','н','г','ш','щ','з','х','ъ','ф','ы','в','а','п','р','о','л','д','ж','э' ,'\\','/','я','ч','с','м','и','т','ь','б','ю','.'],
  EN: ['Q','W','E','R','T','Y','U','I','O','P','{','}','A','S','D','F','G','H','J','K','L',':','\"','|','>','Z','X','C','V','B','N','M','<','>','\?','q','w','e','r','t','y','u','i','o','p','[',']','a','s','d','f','g','h','j','k','l',';','\'','\\','<','z','x','c','v','b','n','m',',','.','/']
}
var linesNumber=0;
console.log(direct);
  var readable = fs.createReadStream(__dirname+inFile,'utf8');

  var writeable = fs.createWriteStream(__dirname+outFile);

  readable.on('readable', function(chunk) {
    var buffer='';
    while (null !== (chunk = readable.read(1))) {
      for(var a=0;a<decode[direct[0]].length;a++){
        if(chunk==decode[direct[0]][a]){
          //console.log(K[direct[0]]);
          //console.log(K[x]);
          //RU Array = K['RU']
          chunk=decode[direct[1]][a];
        }
      }
      if(chunk=='\n'){//if new line symbol in stream
        if(addChar){
          buffer+=addChar;
        }//messy code add char at the end of line
        //buffer+='\n';
        if(addNum>0){
        var tempNumAdd=addNum;
          for(;tempNumAdd>-1;tempNumAdd--){
            var tempString = buffer;
            tempString += tempNumAdd;
            tempString+='\n';
            linesNumber=counter(linesNumber);
            //buffer+='\n';
            writeable.write(tempString);//collect data and write to file
            tempString='';
          }
        }
        writeable.write(buffer);//collect data and write to file
        buffer='';//clear buffer
        linesNumber=counter(linesNumber);//update counter of the lines
        console.log(linesNumber+' Lines converted');//inform user
        //console.log(chunk);//shows current symbol
      }
      buffer+=chunk;
      //console.log(chunk); // chunk is one symbol
    }
  });
}
module.exports=convert;

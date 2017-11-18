const counter = require('./counter')
const fs = require('fs');
const async = require('async');
const path = require('path');


var convert=(inFile,outFile,direct,addChar,addNum)=>{
const RU=['Й','Ц','У','К','Е','Н','Г','Ш','Щ','З','Х','Ъ','Ф','Ы','В','А','П','Р','О','Л','Д','Ж','Э' ,'/','|','Я','Ч','С','М','И','Т','Ь','Б','Ю',',' ,'й','ц','у','к','е','н','г','ш','щ','з','х','ъ','ф','ы','в','а','п','р','о','л','д','ж','э' ,'\\','/','я','ч','с','м','и','т','ь','б','ю','.'];
const EN=['Q','W','E','R','T','Y','U','I','O','P','{','}','A','S','D','F','G','H','J','K','L',':','\"','|','>','Z','X','C','V','B','N','M','<','>','\?','q','w','e','r','t','y','u','i','o','p','[',']','a','s','d','f','g','h','j','k','l',';','\'','\\','<','z','x','c','v','b','n','m',',','.','/'];
var linesNumber=0;

  var readable = fs.createReadStream(__dirname+inFile,'utf8');

  var writeable = fs.createWriteStream(__dirname+outFile);

  readable.on('readable', function(chunk) {
    var buffer='';
    while (null !== (chunk = readable.read(1))) {
      // if(chunk=='\n')
      // console.log('newLINE!');
      for(var a=0;a<RU.length;a++){
        if(chunk==RU[a]){
          chunk=EN[a];
        }
      }
      buffer+=chunk;
      if(chunk=='\n'){
        writeable.write(buffer);
        buffer='';
        linesNumber=counter(linesNumber);
        console.log(linesNumber+' Lines converted');
        //console.log(chunk);
      }
      //console.log(chunk); // chunk is one symbol
    }
  });
}
module.exports=convert;

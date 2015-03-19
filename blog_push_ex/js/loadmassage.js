$(document).ready(function(){
  $("button").click(function(){
    $.post("http://1.getupinform.sinaapp.com/GetResult.php",
    {request:"0",message:"http://stromai.github.io/"},
    function(data,status){
      alert("Data: " + data + "\nStatus: " + status);
    });
  });
});
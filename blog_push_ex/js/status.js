//使用callback改写

function getMassage(){
	$.post("http://1.getupinform.sinaapp.com/GetResult.php",
    {request:"0",message:"http://stromai.github.io/"},
    function(data,status){
    	alert(status);
    	return data;
      //alert("Data: " + data + "\nStatus: " + status);
    });
}

function showBadge(num){
	data = getMassage();
	alert(data);
	//show in Badge
	if(!num){
		num = 0;	
	}
	var show = num.toString();
	chrome.browserAction.setBadgeText({text: show});
	setTimeout(function(){showBadge(num+1)},10000);
}

showBadge();
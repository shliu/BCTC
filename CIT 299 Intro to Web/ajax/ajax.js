
/*
$(document).ready(function(){
	$("#userinput").keyup(function(){
		var url = "http://district.bluegrass.kctcs.edu/richard.king/Misc/5549448277/piglatin.cgi";
		var params = $(this).val();
		$.post(url, "phrase=" + params, function(data){
			$("#translation").val(data);
			});
		});
	});
*/


function TranslateIt(){
	var xhr;
	var params;
	params = "phrase=" + encodeURIComponent(document.getElementById("userinput").value);
	xhr = new XMLHttpRequest();
	xhr.open("POST", "http://district.bluegrass.kctcs.edu/richard.king/Misc/5549448277/piglatin.cgi", true);
	xhr.setRequestHeader("Content-type", "application/x-www-form-urlencoded");
	xhr.setRequestHeader("Content-length", params.length);
	xhr.setRequestHeader("Connection", "close");
	
	xhr.onreadystatechange = function(){
		if (xhr.readyState == 4)
			if (xhr.status == 200)
				document.getElementById("translation").value = xhr.responseText;
			else
				document.getElementById("translation").value = "Error1";
		else
			document.getElementById("translation").value = "Error2";
		};
		
	xhr.send(params);
	}


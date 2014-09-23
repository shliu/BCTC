function do_q2() {
	var xhr;
	var params;
	
	params = "phrase=" + encodeURIComponent(document.getElementById("input").value);
	
	xhr = new XMLHttpRequest();
	xhr.open("POST", "http://district.bluegrass.kctcs.edu/richard.king/Misc/4281033211/palindrome.cgi", true);
	xhr.setRequestHeader("Content-type", "application/x-www-form-urlencoded");
	xhr.setRequestHeader("Content-length", params.length);
	xhr.setRequestHeader("Connection", "close");
	
	xhr.onreadystatechange = function(){
		if (xhr.readyState == 4)
			if (xhr.status == 200)
				document.getElementById("output").value = xhr.responseText;
			else //status != 200
				document.getElementById("output").value = "status != 200";
		else //readystate != 4
			document.getElementById("output").value = "readystate != 4";
		};
	
	xhr.send(params);
	}
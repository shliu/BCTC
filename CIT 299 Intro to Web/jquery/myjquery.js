/*
crash course on jQuery:
	The basic idea of jQuery is much like CSS - we want to separate javascript entirely 
		from html.  So the end result is 3 files: pure HTML file that deals only with content,
		pure CSS file that deals only with design, and a pure javascript file that deals only 
		with programming
	
	In the past the way we got javascript into html is by using the html event handlers
		Eg: onclick="javascript code;", onkeyup="javascript code;", onload="javascript code;"
		This method allowed clear identification of what element initiated the javascript code
		For example, 
		<input type="button" value="mybutton" onclick="alert('hello');"/> 
		would tell us that the button with the value "mybutton" will initiate the code for an 
		alert box with text "hello"
		
	However, now that we have completely separated the javascript from the html, we need a way to know
		what element initiated what javascript code.  This is where jQuery begins - we have to "select"
		an element using a selector.  They look like this in general: $("selector")
		Eg: 
		$("p") //selects all paragraph tag elements in the html
		$(":button") //selects all <input type="button"/> elements
		$("#idname") //selects the element with <id="idname">
		$(".classname") //selects all elements with <class="classname">
		$("div").filter("selector") //selects all div element, but only with matching selector
			would match this: <div w/matching selectors></div>
		$("div").not("selector") //does the exact opposite of .filter()
		$("div[class^='abc']") //selects all div elements, but only div elements with class name starting 
			with "abc" would match this: <div class="abcdefg"></div>
			
	Once we have selected element we want to modify, we now tell jQuery what to do when selected element is
		modified.  This will be very similar to the event handlers in html - think onclick, onload, onkeyup, etc
		Eg: 
		$("p").hover(function{do stuff here;}) 
			//performs javascript when mouse hovers over any paragraph element
		$(":button[name='Hi!']").click(function{do stuff here;})
			//performs javascript when <input type="button" name="Hi!"/> is clicked
			
	And of course we can modifty the selected element, or get information about element with
		$(selector).css({property: 'value', property2: 'value2'})	//changes element's css
		$(selector).attr("attribute_name")	//gets element's attribute_name value
		$(selector).slideDown("slow")	//slides down element slowly
		
	So the basic format of all jQuery looks like this:
		$(selector).event(function(){
			$(this).dostuffhere();	//"$(this)" refers to the selected element
			});
		Eg:
		//this jQuery will change any paragraph the user clicks on to have a background color of yellow
		$("p").click(function(){
			$(this).css({backgroundColor: 'yellow'});
			});
*/


$(document).ready(function(){
	//this jQuery will change any paragraph the user clicks on to have a background color of yellow
	$("p").click(function(){
			$(this).css({backgroundColor: 'yellow'});
			});
			
	//sliding menus when mousing over button
	$(":button[value^='Popup']").hover(function(){
		var here = $(this).position();
		var id = "#" + $(this).attr("value");
		$(id).slideToggle("slow").css({left: here.left, top: here.top+30});
		});
	
	//defines draggable items
	$(".box").draggable({
		stack: "*", 
		snap: "td", 
		snapMode: "inner",
		drag: function() {
			$(this).addClass("transparency");
			},
		stop: function() {
			$(this).removeClass("transparency");
			}
		});
	
	//defines droppable items and what happens when draggable is dropped onto them
	$("td").droppable({
		tolerance: 'pointer', //detects drop as long as mouse pointer is inside box
		drop: function(event, ui){
			var dragged = $(ui.draggable).attr("id");
			var dropped = $(this).attr("id");
			alert (dragged + " dropped onto " + dropped);
			}
		});
	
	//changes board color
	$(":button[value='Change board color']").click(function(){
		var stuff = "#" + $("input:text[name='color']").attr("value");
		$("table").css("background-color", stuff);
		});
	
	//display draggable/droppable directions
	$("table").hover(
		//on hover
		function(event){
			var here = $(this).position();
			$("#table_direction").fadeIn("fast").css({top: here.top-30, left: here.left+50});
			},
		//on unhover
		function(event){
			$("#table_direction").fadeOut("fast");
			}		
		);
	
	//display table color change directions
	$("input:text[name='color']").hover(
		//on hover
		function(event){
			var here = $(this).position();
			$("#input_direction").fadeIn("fast").css({top: here.top-50, left: here.left});
			},
		//on unhover
		function(event){
			$("#input_direction").fadeOut("fast");
			}
		);
	}); //End jQuery document.ready
	
	

	
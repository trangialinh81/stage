	<script type="text/javascript"> 
			indice = 0;
			
				function point_it1(event){
					// recuperer les positions pointus par la souris
					pos_x = event.offsetX?(event.offsetX):event.pageX-document.getElementById("pointer_div2").offsetLeft;
					pos_y = event.offsetY?(event.offsetY):event.pageY-document.getElementById("pointer_div2").offsetTop;
					
					// point.png visible
					
					//document.getElementById("photo").style.left = (pos_x-4) ;
					//document.getElementById("photo").style.top = (pos_y-4) ;
					//document.getElementById("photo").style.visibility = "visible" ;
	
					
					if (indice == 0)
					{
						indice = 1;
						document.pointform.form5_x.value = pos_x;
						document.pointform.form5_y.value = pos_y;
						document.getElementById("photo").style.left = (pos_x - 5) ;
						document.getElementById("photo").style.top = (pos_y-10) ;
						document.getElementById("photo").style.visibility = "visible" ;
					}
					else if (indice == 1)
					{
						indice = 2;
						document.pointform.form6_x.value = pos_x;
						document.pointform.form6_y.value = pos_y;
						document.getElementById("photo2").style.left = (pos_x - 21) ;
						document.getElementById("photo2").style.top = (pos_y - 13) ;
						document.getElementById("photo2").style.visibility = "visible" ;
					}
					else if (indice == 2)
					{
						indice = 3;
						document.pointform.form7_x.value = pos_x;
						document.pointform.form7_y.value = pos_y;
						document.getElementById("photo3").style.left = (pos_x-37) ;
						document.getElementById("photo3").style.top = (pos_y-13) ;
						document.getElementById("photo3").style.visibility = "visible" ;

					}
					else if (indice == 3)
					{
						indice = 4;
						document.pointform.form8_x.value = pos_x;
						document.pointform.form8_y.value = pos_y;
						
						document.getElementById("photo4").style.left = (pos_x - 55) ;
						document.getElementById("photo4").style.top = (pos_y - 13) ;
						document.getElementById("photo4").style.visibility = "visible" ;
					}
				
				}
				 		
				function change(num) {
					document.getElementById("pointer_div2").style.backgroundImage = "url('" + num + "')";
				}
				function relance2(){
					indice =0;
					document.pointform.form5_x.value = "";
					document.pointform.form5_y.value = "";
					document.pointform.form6_x.value = "";
					document.pointform.form6_y.value = "";
					document.pointform.form7_x.value = "";
					document.pointform.form7_y.value = "";
					document.pointform.form8_x.value = "";
					document.pointform.form8_y.value = "";
					document.getElementById("photo").style.visibility = "hidden" ;
					document.getElementById("photo2").style.visibility = "hidden" ;
					document.getElementById("photo3").style.visibility = "hidden" ;
					document.getElementById("photo4").style.visibility = "hidden" ;
				}

			</script>
			
			<p>
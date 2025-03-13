// To create literal strings stored in flash memory enclose your HTML code between 
// F(R"=====( HTML code here )=====");
// If you have 1 reading then you probably have 2 literal strings
// If you have 2 readings then you probably have 3 literal strings etc.

String homePagePart1 = F(R"=====(<!DOCTYPE html>
<html>
<head>
<meta name="viewport" content="width=device-width, initial-scale=1">
<link rel="stylesheet" href="style.css">
<div class="nav-bar">
  <nav>
  <h1 style="color: white;">Robotic arm contol</h1>
  </nav>
    </div>
</head>
<body style="background-color: black;">
  <style>
    .nav-bar{
  width:100%;
  height:50px;
  background-color: red;
  border: 10px;
}





.slidecontainer {
    width: 100%;
    margin-bottom: 20px; /* Space between sliders */
  }
.slider {
    -webkit-appearance: none;
    width: 100%;
    height: 25px;
    background: #d3d3d3;
    outline: none;
    opacity: 0.7;
    -webkit-transition: .2s;
    transition: opacity .2s;
  }
  
  .slider:hover {
    opacity: 1;
  }
  
  .slider::-webkit-slider-thumb {
    -webkit-appearance: none;
    appearance: none;
    width: 25px;
    height: 25px;
    background: #cf1b1b;
    cursor: pointer;
  }
  
  .slider::-moz-range-thumb {
    width: 25px;
    height: 25px;
    background: #111111;
    cursor: pointer;
  }
  
  p {
    font-size: 18px;
    color: #333;
  }
  </style>
  

  
<p style="color: white;">Drag the slider to Control the robot.</p>

<!-- Waist Control -->
<div class="slidecontainer">
  <label for="waist">Waist:</label>
  <input type="range" min="1" max="90" value="45" class="slider" id="waist">
  <p style="color: azure;">Value: <span id="waist-value">45</span></p>
</div>

<!-- Shoulder Control -->
<div class="slidecontainer">
  <label for="shoulder">Shoulder:</label>
  <input type="range" min="1" max="20" value="10" class="slider" id="shoulder">
  <p style="color: azure;">Value: <span id="shoulder-value">10</span></p>
</div>

<!-- Elbow Control -->
<div class="slidecontainer">
  <label for="elbow">Elbow:</label>
  <input type="range" min="1" max="50" value="25" class="slider" id="elbow">
  <p style="color: azure;">Value: <span id="elbow-value">50</span></p>
</div>

<!-- Gripper Control -->
<div class="slidecontainer">
  <label for="gripper">Gripper:</label>
  <input type="range" min="1" max="100" value="50" class="slider" id="gripper">
  <p style="color: azure;">Value: <span id="gripper-value">50</span></p>
</div>

<script>
  function updateSliderValue(sliderId, valueId) {
    var slider = document.getElementById(sliderId);
    var output = document.getElementById(valueId);
    output.innerHTML = slider.value;
  
    slider.oninput = function() {
      output.innerHTML = this.value;
    };
  }
  
  
  updateSliderValue("waist", "waist-value");
  updateSliderValue("shoulder", "shoulder-value");
  updateSliderValue("elbow", "elbow-value");
  updateSliderValue("gripper", "gripper-value");
</script>

<video width="670" controls>
  <source src="Robovid.mp4" type="video/mp4">
  <source src="www.fanuc.eu" type="video/ogg">
  Your browser does not support HTML video.
</video>

<p style="color: azure;">
  Video courtesy of 
  <a href="https://www.fanuc.eu/" target="_blank">Robotic arm</a>.
  </p>
<script src="program.js"></script>
</body>
</html>)=====");

String homePagePart2 = F(R"=====(<!DOCTYPE html>
<html>
<head>
<meta name="viewport" content="width=device-width, initial-scale=1">
<link rel="stylesheet" href="style.css">
<div class="nav-bar">
  <nav>
  <h1 style="color: white;">Robotic arm contol</h1>
  </nav>
    </div>
</head>
<body style="background-color: black;">
  <style>
    .nav-bar{
  width:100%;
  height:50px;
  background-color: red;
  border: 10px;
}





.slidecontainer {
    width: 100%;
    margin-bottom: 20px; /* Space between sliders */
  }
.slider {
    -webkit-appearance: none;
    width: 100%;
    height: 25px;
    background: #d3d3d3;
    outline: none;
    opacity: 0.7;
    -webkit-transition: .2s;
    transition: opacity .2s;
  }
  
  .slider:hover {
    opacity: 1;
  }
  
  .slider::-webkit-slider-thumb {
    -webkit-appearance: none;
    appearance: none;
    width: 25px;
    height: 25px;
    background: #cf1b1b;
    cursor: pointer;
  }
  
  .slider::-moz-range-thumb {
    width: 25px;
    height: 25px;
    background: #111111;
    cursor: pointer;
  }
  
  p {
    font-size: 18px;
    color: #333;
  }
  </style>
  

  
<p style="color: white;">Drag the slider to Control the robot.</p>

<!-- Waist Control -->
<div class="slidecontainer">
  <label for="waist">Waist:</label>
  <input type="range" min="1" max="90" value="45" class="slider" id="waist">
  <p style="color: azure;">Value: <span id="waist-value">45</span></p>
</div>

<!-- Shoulder Control -->
<div class="slidecontainer">
  <label for="shoulder">Shoulder:</label>
  <input type="range" min="1" max="20" value="10" class="slider" id="shoulder">
  <p style="color: azure;">Value: <span id="shoulder-value">10</span></p>
</div>

<!-- Elbow Control -->
<div class="slidecontainer">
  <label for="elbow">Elbow:</label>
  <input type="range" min="1" max="50" value="25" class="slider" id="elbow">
  <p style="color: azure;">Value: <span id="elbow-value">50</span></p>
</div>

<!-- Gripper Control -->
<div class="slidecontainer">
  <label for="gripper">Gripper:</label>
  <input type="range" min="1" max="100" value="50" class="slider" id="gripper">
  <p style="color: azure;">Value: <span id="gripper-value">50</span></p>
</div>

<script>
  function updateSliderValue(sliderId, valueId) {
    var slider = document.getElementById(sliderId);
    var output = document.getElementById(valueId);
    output.innerHTML = slider.value;
  
    slider.oninput = function() {
      output.innerHTML = this.value;
    };
  }
  
  
  updateSliderValue("waist", "waist-value");
  updateSliderValue("shoulder", "shoulder-value");
  updateSliderValue("elbow", "elbow-value");
  updateSliderValue("gripper", "gripper-value");
</script>

<video width="670" controls>
  <source src="Robovid.mp4" type="video/mp4">
  <source src="www.fanuc.eu" type="video/ogg">
  Your browser does not support HTML video.
</video>

<p style="color: azure;">
  Video courtesy of 
  <a href="https://www.fanuc.eu/" target="_blank">Robotic arm</a>.
  </p>
<script src="program.js"></script>
</body>
</html>)=====");

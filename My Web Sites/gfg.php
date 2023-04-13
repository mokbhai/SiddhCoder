<?php
	
	if ($_SERVER['REQUEST_METHOD'] == 'POST') {
		
		function get_data() {
			$datae = array();
			$datae[] = array(
				'Date' => $_POST['date'],
				'Study' => $_POST['study'],
				'Code' => $_POST['code'],
				'Book' => $_POST['book'],
				'Gym' => $_POST['gym'],
			);
			return json_encode($datae);
		}
		
		
		
		$name = "done";
		$file_name = $name . '.json';
	
		if(file_put_contents(
			"$file_name", get_data())) {
				echo $file_name .' file created';
			}
		else {
			echo 'There is some error';
		}
	}
?>

<?php
require_once("defines.php");

function draw_graph($datay, $data2y, $label_x) {
	include_once("src/jpgraph.php");
	include_once("src/jpgraph_line.php");
	
	
	// A nice graph with anti-aliasing
	$graph = new Graph(800,600,"auto");
	$graph->img->SetMargin(40,180,40,40);	
	
	$graph->img->SetAntiAliasing("white");
	$graph->SetScale("textlin");
	$graph->SetShadow();
	$graph->title->Set("Nodes and Comment Count By Duration");
	$graph->xaxis->SetTickLabels($label_x);
	
	
	// Use built in font
	$graph->title->SetFont(FF_FONT1,FS_BOLD);
	
	// Slightly adjust the legend from it's default position in the
	// top right corner. 
	$graph->legend->Pos(0.05,0.5,"right","center");
	
	// Create the first line
	if($datay) {
		$p1 = new LinePlot($datay);
		$p1->mark->SetType(MARK_FILLEDCIRCLE);
		$p1->mark->SetFillColor("blue");
		$p1->mark->SetWidth(4);
		$p1->SetColor("blue");
		$p1->SetCenter();
		$p1->SetLegend("Nodes Count");
		$graph->Add($p1);
	}
	
	// ... and the second
	if($data2y) {
		$p2 = new LinePlot($data2y);
		$p2->mark->SetType(MARK_STAR);
		$p2->mark->SetFillColor("red");
		$p2->mark->SetWidth(4);
		$p2->SetColor("red");
		$p2->SetCenter();
		$p2->SetLegend("Comments Count");
		$graph->Add($p2);
	}
		
	// Output line
	$graph->Stroke();
	
}


$duration = $_GET["duration"];
$show_comments = $_GET["show_comments"];
$show_nodes = $_GET["show_nodes"];


if($duration == "lastYear") {
	
	if($show_nodes) {
		// nodes per month
		$node_stat_dom = new DOMDocument();
		$node_stat_dom->load(SERVICE_ENDPOINT."/nodesCountPerMonth");
		
		$count_elements = $node_stat_dom->getElementsByTagName("count");
		$prior_month_elements = $node_stat_dom->getElementsByTagName("priorMonth");
		
		$node_count_values = array();
		for($i = 0; $i< $count_elements->length; $i ++) {
			$count = $count_elements->item($i)->nodeValue;
			$prior_month = $prior_month_elements->item($i)->nodeValue;
			
			$node_count_values[$prior_month] = $count;
		}
	}
	
	if($show_comments) {
		// comments per month
		$coment_stat_dom = new DOMDocument();
		$coment_stat_dom->load(SERVICE_ENDPOINT."/commentsCountPerMonth");
		$count_elements = $coment_stat_dom->getElementsByTagName("count");
		$prior_month_elements = $coment_stat_dom->getElementsByTagName("priorMonth");
		
		$comment_count_values = array();
		for($i = 0; $i< $count_elements->length; $i ++) {
			$count = $count_elements->item($i)->nodeValue;
			$prior_month = $prior_month_elements->item($i)->nodeValue;
			
			$comment_count_values[$prior_month] = $count;
		}
	}
	
	// loop through 1 to 12
	$node_count_seq = array();
	$comment_count_seq = array();
	$labelx = array();
	
	for($i = 11; $i >= 0; $i --) {
		if($show_nodes) {
			if(array_key_exists($i, $node_count_values)) {
				$node_count_seq []= $node_count_values[$i];
			}
			else {
				$node_count_seq []= 0;
			}
		}
		if($show_comments) {
			if(array_key_exists($i, $comment_count_values)) {
				$comment_count_seq []= $comment_count_values[$i];
			}
			else {
				$comment_count_seq []= 0;
			}
		}
		$timestamp = time() - 60*60*24*30*$i;
		$labelx [] = date("M", $timestamp);
	}
	if($show_nodes) {
		$datay = $node_count_seq;
	}
	else {
		$datay = NULL;
	}
	if($show_comments) {
		$datay2 = $comment_count_seq;
	}
	else {
		$datay2 = NULL;
	}
	
	
	
	if($show_nodes || $show_comments) {
		draw_graph($datay, $datay2, $labelx);
	}
	
}
else if($duration == "last5Years") {
		
	if($show_nodes) {
		// nodes per year
		$node_stat_dom = new DOMDocument();
		$node_stat_dom->load(SERVICE_ENDPOINT."/nodesCountPerYear");
		
		$count_elements = $node_stat_dom->getElementsByTagName("count");
		$prior_year_elements = $node_stat_dom->getElementsByTagName("priorYear");
		
		$node_count_values = array();
		for($i = 0; $i< $count_elements->length; $i ++) {
			$count = $count_elements->item($i)->nodeValue;
			$prior_year = $prior_year_elements->item($i)->nodeValue;
			
			$node_count_values[$prior_year] = $count;
		}
	}
		
	if($show_comments) {	
		// comments per year
		$coment_stat_dom = new DOMDocument();
		$coment_stat_dom->load(SERVICE_ENDPOINT."/commentsCountPerYear");
		$count_elements = $coment_stat_dom->getElementsByTagName("count");
		$prior_year_elements = $coment_stat_dom->getElementsByTagName("priorYear");
		
		$comment_count_values = array();
		for($i = 0; $i< $count_elements->length; $i ++) {
			$count = $count_elements->item($i)->nodeValue;
			$prior_year = $prior_year_elements->item($i)->nodeValue;
			
			$comment_count_values[$prior_year] = $count;
		}
	}
	
	// loop through 1 to 5
	$node_count_seq = array();
	$comment_count_seq = array();
	$labelx = array();
	
	for($i = 4; $i >= 0; $i --) {
		if($show_nodes) {
			if(array_key_exists($i, $node_count_values)) {
				$node_count_seq []= $node_count_values[$i];
			}
			else {
				$node_count_seq []= 0;
			}
		}
		if($show_comments) {
			if(array_key_exists($i, $comment_count_values)) {
				$comment_count_seq []= $comment_count_values[$i];
			}
			else {
				$comment_count_seq []= 0;
			}
		}
		$timestamp = time() - 60*60*24*365*$i;
		$labelx [] = date("Y", $timestamp);
	}
	if($show_nodes) {
		$datay = $node_count_seq;
	} else {
		$datay = NULL;
	}
	if($show_comments) {
		$datay2 = $comment_count_seq;
	}
	else {
		$datay2 = NULL;
	}
	
	
	if($show_nodes || $show_comments) {
		draw_graph($datay, $datay2, $labelx);
	}
}
else if($duration == "lastMonth") {// this is last 30 days
	
	if($show_nodes) {
		// nodes per day
		$node_stat_dom = new DOMDocument();
		$node_stat_dom->load(SERVICE_ENDPOINT."/nodesCountPerDay");


		$count_elements = $node_stat_dom->getElementsByTagName("count");
		$prior_day_elements = $node_stat_dom->getElementsByTagName("priorDate");

		$node_count_values = array();
		for($i = 0; $i< $count_elements->length; $i ++) {
			$count = $count_elements->item($i)->nodeValue;
			$prior_day = $prior_day_elements->item($i)->nodeValue;
			
			$node_count_values[$prior_day] = $count;
		}
	}
	
	if($show_comments) {
		// comments per day
		$coment_stat_dom = new DOMDocument();
		$coment_stat_dom->load(SERVICE_ENDPOINT."/commentsCountPerDay");
		$count_elements = $coment_stat_dom->getElementsByTagName("count");
		$prior_day_elements = $coment_stat_dom->getElementsByTagName("priorDate");
		
		$comment_count_values = array();
		for($i = 0; $i< $count_elements->length; $i ++) {
			$count = $count_elements->item($i)->nodeValue;
			$prior_day = $prior_day_elements->item($i)->nodeValue;
			
			$comment_count_values[$prior_day] = $count;
		}
	}
	
	// loop through 1 to 30
	$node_count_seq = array();
	$comment_count_seq = array();
	$labelx = array();
	
	for($i = 29; $i >= 0; $i --) {
		if($show_nodes) {
			if(array_key_exists($i, $node_count_values)) {
				$node_count_seq []= $node_count_values[$i];
			}
			else {
				$node_count_seq []= 0;
			}
		}
		if($show_comments) {
			if(array_key_exists($i, $comment_count_values)) {
				$comment_count_seq []= $comment_count_values[$i];
			}
			else {
				$comment_count_seq []= 0;
			}
		}
		$timestamp = time() - 60*60*24*$i;
		$labelx [] = date("d", $timestamp);
	}
	if($show_nodes) {
		$datay = $node_count_seq;
	}
	else {
		$datay = NULL;
	}
	if($show_comments) {
		$datay2 = $comment_count_seq;
	}
	else {
		$datay2 = NULL;
	}
	
	if($show_nodes || $show_comments) {
		draw_graph($datay, $datay2, $labelx);
	}
}
else { // this is last 24 hours
	
	if($show_nodes) {
		// nodes per day
		$node_stat_dom = new DOMDocument();
		$node_stat_dom->load(SERVICE_ENDPOINT."/nodesCountPerHour");


		$count_elements = $node_stat_dom->getElementsByTagName("count");
		$prior_hour_elements = $node_stat_dom->getElementsByTagName("priorHour");

		$node_count_values = array();
		for($i = 0; $i< $count_elements->length; $i ++) {
			$count = $count_elements->item($i)->nodeValue;
			$prior_hour = $prior_hour_elements->item($i)->nodeValue;
			
			$node_count_values[$prior_hour] = $count;
		}
	}
	
	if($show_comments) {
		// comments per day
		$coment_stat_dom = new DOMDocument();
		$coment_stat_dom->load(SERVICE_ENDPOINT."/commentsCountPerHour");
		$count_elements = $coment_stat_dom->getElementsByTagName("count");
		$prior_hour_elements = $coment_stat_dom->getElementsByTagName("priorHour");
		
		$comment_count_values = array();
		for($i = 0; $i< $count_elements->length; $i ++) {
			$count = $count_elements->item($i)->nodeValue;
			$prior_hour = $prior_hour_elements->item($i)->nodeValue;
			
			$comment_count_values[$prior_hour] = $count;
		}
	}
	
	// loop through 1 to 30
	$node_count_seq = array();
	$comment_count_seq = array();
	$labelx = array();
	
	for($i = 23; $i >= 0; $i --) {
		if($show_nodes) {
			if(array_key_exists($i, $node_count_values)) {
				$node_count_seq []= $node_count_values[$i];
			}
			else {
				$node_count_seq []= 0;
			}
		}
		
		if($show_comments) {
			if(array_key_exists($i, $comment_count_values)) {
				$comment_count_seq []= $comment_count_values[$i];
			}
			else {
				$comment_count_seq []= 0;
			}
		}
		$timestamp = time() - 60*60*$i;
		$labelx [] = date("H", $timestamp);
	}
	if($show_nodes) {
		$datay = $node_count_seq;
	}
	else {
		$datay = NULL;
	}
	if($show_comments) {
		$datay2 = $comment_count_seq;
	}
	else {
		$datay2 = NULL;
	}
	
	if($show_nodes || $show_comments) {
		draw_graph($datay, $datay2, $labelx);
	}
}


//draw_graph($datay, $data2y, $label_x);


?>

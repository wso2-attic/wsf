<?php
$tracking_user_name= "anonymous";
if(isset($username) && !empty($username)) {
	$tracking_user_name= $username;
}
    echo <<<TEXT
        <script src="http://www.google-analytics.com/urchin.js" type="text/javascript">
        </script>
        <script type="text/javascript">
        _uacct = "UA-3343847-7";
        urchinTracker();
        </script>
<script type="text/javascript"
src="http://cheetara.wso2.com/st/res/jq.js"></script>
<script type="text/javascript"
src="http://cheetara.wso2.com/st/res/stats.js"></script>
<script>
    var type="labPHP";
    stat_init();
    var i = new Image();
    i.src = "http://cheetara.wso2.com/st/stats.php?name={$tracking_user_name}&email=anonymous@xx.xx&desc="+ document.title + "&type="
+ type + "&url=" + window.location.href;
</script>

TEXT;
?>

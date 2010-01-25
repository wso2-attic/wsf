<!-- Starting template for the WSF/PHP DEMO Site -->

		<div id="header">
			<table width="100%" cellspacing="0" cellpadding="0" border="0">
				<tbody>
					<tr>
						<td class="logo-position">
							<div class="logo-position">
							<?php
								if(WEB_VERSION == "php")
								{
							?>
								<span class="edit-link">
									<a href="http://wso2.org/projects/wsf/php">
										<img border="0" src="./images/logo/wsf-php-logo.gif"/>
									</a>
									<a href="http://wso2.org/projects/wsf/php" style="padding-top:10px">
										<h1 style="font-size:15px; text-decoration: none;">Best-of-breed PHP Web services</h1>
									</a>
								</span>
							<?php
								} else if(WEB_VERSION == "c")
								{
							 ?>
								<span class="edit-link">
									<a href="http://wso2.org/projects/wsf/c">
										<img border="0" src="images/logo/wsf-c-logo.gif"/>
									</a>
									<a href="http://wso2.org/projects/wsf/c" style="padding-top:10px">
										<h1 style="font-size:15px; text-decoration: none;">C Web Services</h1>
									</a>
								</span>
							 	
							 <?php
								}
							  ?>
							</div>
						</td>
						<td class="version">&nbsp;</td>
						<td class="user_links">
							<ul>
								<?php
								if($aschild)
								{
									if($username === NULL)
									{
										$sign_up_page = SIGN_UP_PAGE;
										echo "<li><a class=\"home\" href=\"javascript:move_to_here('index.php')\">Home</a></li><li><a class=\"sign_in\" href=\"javascript:move_to_here('login.php')\">Sign in</a></li><li><a class=\"sign_up\" href=\"javascript:move_to_here('{$sign_up_page}')\">Sign up</a></li>";
									}
									else
									{
										echo "<li><a class=\"home\" href=\"javascript:move_to_here('index.php')\">Home</a></li><li><a class=\"change_user\" href=\"javascript:move_to_here('change_user.php')\">Change User</a></li><li><a class=\"sign_out\" href=\"javascript:move_to_here('logout.php')\">Sign out as {$username}</a></li>";
									}
								}
								else
								{
									if($username === NULL)
									{
										$sign_up_page = SIGN_UP_PAGE;
										echo "<li><a class=\"home\" href=\"index.php\">Home</a></li><li><a class=\"sign_in\" href=\"login.php\">Sign in</a></li><li><a class=\"sign_up\" href=\"{$sign_up_page}\">Sign up</a></li>";
									}
									else
									{
										echo "<li><a class=\"home\" href=\"index.php\">Home</a></li><li><a class=\"change_user\" href=\"change_user.php\">Change User</a></li><li><a class=\"sign_out\" href=\"logout.php\">Sign out as {$username}</a></li>";
									}
								}
								?>
							</ul>
						</td>
					</tr>
				</tbody>
			</table>
		</div>

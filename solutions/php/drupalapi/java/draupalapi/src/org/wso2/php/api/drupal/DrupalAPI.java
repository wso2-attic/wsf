package org.wso2.php.api.drupal;

/**
 * Created by IntelliJ IDEA.
 * User: Dimuthu Gamage
 * Date: Oct 17, 2008
 * Time: 11:11:26 AM
 */
public class DrupalAPI {
    public int postBlog(Blog post) {
        return 0;
    }
    public Blog[] getNodes() {
        return null;
    }

    public int postComment(Comment comment) {
        return 0;
    }
    public Comment[] getComments() {
        return null;
    }
    public Comment[] getCommentsForBlog(int blogId) {
        return null;
    }

    public int registerUser(User user) {
        return 0;
    }
    public User[] getUsers() {
        return null;
    }
}

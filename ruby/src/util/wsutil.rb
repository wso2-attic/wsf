require 'WSFC'

class WSUtil

  def WSUtil.file_put_base64_content(file_name, base64_content, content_type = "application/octet-stream")

    return false unless file_name.kind_of? String and
                        base64_content.kind_of? String and
                        content_type.kind_of? String

    return false if file_name.empty? or
                    base64_content.empty? or
                    content_type.empty?

    file_name_with_ext = file_name
    file_name_with_ext + ".jpg" if content_type == "image/jpeg"

    return WSFC::ruby_file_put_base64_content(file_name_with_ext, base64_content) ? true : false

  end

end

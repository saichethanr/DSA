        String a = "programming";
        String result = a.chars().distinct().mapToObj(c->String.valueOf((char)c)).collect(Collectors.joining());
        System.out.println(result);